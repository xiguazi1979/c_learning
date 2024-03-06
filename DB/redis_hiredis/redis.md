# Linux安装redis服务和安装hiredis库
https://zhuanlan.zhihu.com/p/599816240 
git clone https://gitee.com/mirrors/redis.git -b 6.2 
NOTE: Note that SET with EXAT option for expiration time is available for redis 6.2 and later, for older redis version, use EX option instead.

## Pros
Per entry time-to-live in seconds, milliseconds or specific expiration time for each entry
## Cons
Cannot search base on arbitrary field, care must be taken in storage design and secondary indexing

# programming
https://zhuanlan.zhihu.com/p/660575286 

# Redis（Remote Dictionary Server )
远程字典服务，是一个开源的使用ANSI C语言编写、支持网络、可基于内存亦可持久化的日志型、Key-Value数据库，并提供多种语言的API。Redis属于非关系型数据库中的一种解决方案，目前也是业界主流的缓存解决方案组件。
2、为什么用它
Redis是当前互联网世界最为流行的 NoSQL（Not Only SQL）数据库，它的性能十分优越，其性能远超关系型数据库，可以支持每秒十几万此的读/写操作，并且还支持集群、分布式、主从同步等配置，理论上可以无限扩展节点，它还支持一定的事务能力，这也保证了高并发的场景下数据的安全和一致性。
Redis 已经成为 IT 互联网大型系统的标配，熟练掌握 Redis 成为开发、运维人员的必备技能。

支持 Strings, Lists, Hashes, Sets 及 Ordered Sets 数 据类型操作。

命令表是一个字典，字典的键是一个个命令名字，比如"set"、"get"、"del"等等。而字典的值则是一个个redisCommand结构，每个redisCommand结构记录了一个Redis命令的实现信息

## 事务，大家可能最先想到的就是关系型数据库中的事务管理，其实redis中的事务也有类似的特点：

隔离性：事务是一个单独的隔离操作，事务中的所有命令都会序列化、按顺序地执行。事务在执行的过程中，不会被其他客户端发送来的命令请求所打断。
原子性：事务是一个原子操作，事务中的命令要么全部被执行，要么全部都不执行。
但是redis的事务和关系型数据库的事务有一个最大的区别：redis事务不会回滚，即使事务中有某条/某些命令执行失败了， 事务队列中的其他命令仍然会继续执行完毕。
为什么 Redis 不支持回滚（roll back）?

redis官方文档中大概是这样解释的：

1）redis 命令只会因为错误的语法而失败，或是命令用在了错误类型的键上面：也就是说，从实用性的角度来说，失败的命令是由编程错误造成的，而这些错误应该在开发的过程中被发现，而不应该带到生产环境中。

2）因为不需要对回滚进行支持，所以 Redis 的内部可以保持简单且快速。
## 十一、内存淘汰策略
1、过期删除策略
Redis提供了四个命令来设置过期时间（生存时间）。
十一、内存淘汰策略
1、过期删除策略
Redis提供了四个命令来设置过期时间（生存时间）。
十一、内存淘汰策略
1、过期删除策略
Redis提供了四个命令来设置过期时间（生存时间）。

## 常用命令
（1）select命令：选择不同编号的数据库；

          ● redis数据库默认是0-15；

          ● redis不同数据库之间存储的数据是不一样的，在进行redis设计的时候，我们可以做好规划；比如我们可以在0号数据库中存储人员信息、1号数据库存储订单信息、2号数据库保存商品信息。这样一来，通过不同的数据库，我们就可以区分开不同类型的数据了；

（2） set命令：设置值；

          ● redis是键值对类型的非关系型数据库，里面的所有数据都是采用key-value的方式出现；

          ● 如【set name lily】：意思是在当前数据库中增加一个key=name，value=lily的数据；

（3）get命令：将对应key的value提取出来

          ● 如【get hello】：意思是获取key=hello的数据的value；

（4）keys命令：使用一个通配符表达式，查询当前数据库中所有满足通配符表达式要求的key；

          ● 如【keys he*】：获取当前数据库中，所有key以he开头的，所有key的集合；

（5）dbsize命令：返回当前数据库中键值对的总数；

（6）exists命令：检查某个key在当前数据库中是否已经存在；

          ● 如【exists a】：意思是检查当前数据库中，是否已经存在key=a的数据；

（7）del命令：根据key值删除数据；

          ● 如【del a】：意思是删除key=a的那条数据；

（8）expire命令；ttl命令；这两个命令一般是一起使用的；

          ● 在redis中我们可以给某条数据的key设置一个有效期；

          ● 在有效期内，这个key就是存活的，那么这条数据也是存活的；

          ● 有效期一旦到期，这个key就会自动被redis销毁，自然这条数据也会被销毁；

          ● 如【expire hello 20】：意思是设置key=hello20秒后过期
