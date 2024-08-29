## I2C bus， 及其子集 SMBus
对主CPU而言，通常使用GPIO管脚来配置为i2c. 比如STM32 芯片有多个 I2C 外设，它们的 I2C 通讯信号引出到不同的 GPIO 引脚上，使用时必须配置到这些指定的引脚。
I2C设备地址为7位。一般的I2C设备通过管脚A0-A2的物理连线置为或高或低的地址低三位，高四位一般为固定死的（根据期间本身内部文档定好的）。

## I2C 的作用，复杂环境下MUX的意义
https://www.ti.com.cn/cn/lit/ta/ssztc18/ssztc18.pdf?ts=1724836599692 
Electronic products such as smartphones, tablets, TVs, cars … even refrigerators and washing machines have
added more and more features over the last few years to make life easier for users. To play games and monitor
your health on a smartphone, you need haptic control and a touchscreen interface, which require additional
sensors. Other systems in the automotive, industrial, communication markets have also added more sensors

switch （解决同一个地址的多个器件的连接问题，使用通道概念） / repeater （增强总线下挂的上下拉驱动能力，改善SCL in/out波形）

## I2C多路复用器TCA9548A使用
https://www.ti.com.cn/product/cn/TCA9548A/part-details/TCA9548APWR 
https://leung-manwah.blog.csdn.net/article/details/128684825 

TCA9548本身I2C地址分配
TCA9548A 是一个 I2C 器件，本身有 I2C 地址。TCA9548A 自身的地址和它 A0，A1，A2 口的电平状态有关，组合出 8 个 I2C 地址。默认地址为0x70（A0，A1，A2全部接地），最大地址为0x77（A0，A1，A2全部上拉）。

比如这样硬件连接A0-A2，给予不同地址后，从 MCU 的一路 I2C 最多可以接入 8 个T CA9548A 芯片

I2C选择通道命令
TCA9548A 只有一个 8 位寄存器，将某一位置1，说明将哪个通道开通。TCA9548A 就会保持这个通道，并透传 I2C 的消息，就可以直接向操作 I2C 从设备一样发数据了。

MUX driver:
https://docs.kernel.org/5.10/i2c/i2c-topology.html 
In drivers/i2c/muxes/:
               .----------.     .--------.
.--------.     |   mux-   |-----| dev D1 |
|  root  |--+--|  locked  |     '--------'
'--------'  |  |  mux M1  |--.  .--------.
            |  '----------'  '--| dev D2 |
            |  .--------.       '--------'
            '--| dev D3 |
               '--------'
When there is an access to D1, this happens:

        Someone issues an I2C transfer to D1.
        M1 locks muxes on its parent (the root adapter in this case).
        M1 calls ->select to ready the mux.
        M1 (presumably) does some I2C transfers as part of its select. These transfers are normal I2C transfers that locks the parent adapter.
        M1 feeds the I2C transfer from step 1 to its parent adapter as a normal I2C transfer that locks the parent adapter.
        M1 calls ->deselect, if it has one.
        Same rules as in step 4, but for ->deselect.
        M1 unlocks muxes on its parent.


## I2C设备实例化 (不同于动态probe)
https://docs.kernel.org/5.10/i2c/instantiating-devices.html 
Unlike PCI or USB devices, I2C devices are not enumerated at the hardware level. Instead, the software must know which devices are connected on each I2C bus segment, and what address these devices are using.  

In general, the kernel should know which I2C devices are connected and what addresses they live at. However, in certain cases, it does not, so a sysfs interface was added to let the user provide the information.
new_device takes 2 parameters: the name of the I2C device (a string) and the address of the I2C device (a number, typically expressed in hexadecimal starting with 0x, but can also be expressed in decimal.)
echo eeprom 0x50 > /sys/bus/i2c/devices/i2c-3/new_device
### i2c-init.py
        self.i2c_mux0_devices = ([
            # HWM
            ('adt7476', 0x2e, 2),
            # initialize multiplexer (PCA9548 #2)
            ('pca9548', 0x76, 3),  
            # CPLD1
            ('CPLD1', 0x63, 4),    // driver/address/bus
            #CPLD2
            ('CPLD2', 0x64, 5),
            # initialize multiplexer (PCA9548 #3)
            ('pca9548', 0x76, 6),
            # initialize multiplexer (PCA9548 #4)
            ('pca9548', 0x76, 9),
            ])


            ########### initialize I2C bus PCA9545 #0 ###########
            i2c_utils.create_devices(self.i2c_mux0_devices)

            ########### initialize I2C bus PCA9545 #1 ###########
            i2c_utils.create_devices(self.i2c_mux1_devices_sda3016ss2)

    def create_devices(dev_list):
        for (driver, addr, bus_num) in dev_list:
            i2c_utils.create_device(driver, addr, bus_num)

class i2c_utils():
    @staticmethod
    def create_device(driver, addr, bus_num):
        bus = '/sys/bus/i2c/devices/i2c-%d' % bus_num    // CPLD WD: i2c-4
        ddir = "%s/%d-%4.4x" %(bus, bus_num, addr)       // i2c-4/4-0x76

        busdir = "%s/new_device" % bus    //i2c-4/new_device
        if not Path(ddir).exists():
            try:
                with open(busdir, "w") as f:
                    f.write("%s 0x%x\n" %(driver, addr))    //CPLD 0x76 -> i2c-4/new_device
            except BaseException as e:
                writelog("Unexpected error initialize device %s:0x%x:%s: %s" % (driver, addr, bus, e))
        else:
            writelog("Device %s:%x:%s already exists." % (driver, addr, bus))

i2cset -y -f 4 0x63 0x39 0x01  #thus for bus 4 (virtual), address 0x63 device (CPLD), write its register 0x39 as 1

## I2C死锁
https://blog.csdn.net/m0_74976404/article/details/136954526 
IIC总线在进行数据传送时，时钟线SCL为低电平期间发送器向数据线上发送一位数据，在此期间数据线上的信号允许发生变化，时钟线SCL为高电平期间接收器从数据线上读取一位数据，在此期间数据线上的信号不允许发生变化，必须保持稳定。
上述文字总结：时钟线为低电平的时候发送方往数据线上放数据， 高电平器件接收方接收数据。

 当时钟线出现下沿的时候才认为数据被读走了

数据线在等待时钟线的下降沿， 时钟线在等待数据线的高电平， 二者等待的条件一直不成立， 最终造成死锁。

出现死锁的解决办法
（1）可以选用带复位功能的从设备。
（2）在I2C总线上增加一个额外的总线恢复设备。这个设备监视I2C总线。当设备检测到SDA信号被拉低超过指定时间时，就在SCL总线上产生9个时钟 脉冲，使I2C从设备完成读操作，从死锁状态上恢复出来。
（3）在I2C上串人一个具有死锁恢复的I2C缓冲器，如Linear公司的LTC4307是一个双向的I2C总线缓冲器，并且具有I2C总线死锁恢复的功能。
当然，在MUX环境下，我理解下游总线如果被锁了，在CPU侧只能控制上游总线SCL，因此法2对下游总线也许无效，但法1可以（需要设备支持）