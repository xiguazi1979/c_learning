# VScode
gdb wrapper: e.g. sudo_gdb:
sudo ip netns exec ns1 /usr/bin/gdb "$@"

launch.json example:
        {
            "name": "(gdb) 启动", //配置名称，显示在配置下拉菜单中
            "type": "cppdbg", //配置类型
            "request": "launch", //请求配置类型，可以是启动或者是附加
            "program": "${workspaceFolder}/efmmgr_sim", //程序可执行文件的完整路径，${workspaceFolder}表示远程连接的初始路径
            "args": ["-p/tmp/efmmgr.pid", "-d 1"], //传递给程序的命令行参数
            "stopAtEntry": false,//可选参数，如果为true,调试程序应该在入口（main）处停止
            "cwd": "${workspaceFolder}", //目标的工作目录
            "environment": [], //表示要预设的环境变量
            "externalConsole": false,//如果为true，则为调试对象启动控制台
            "miDebuggerPath": "${workspaceFolder}/sudo_gdb",
            "MIMode": "gdb",//要连接到的控制台启动程序
            "setupCommands": [ //为了安装基础调试程序而执行的一个或多个GDB/LLDB命令
                {
                    "description": "为 gdb 启用整齐打印",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ]
        }
