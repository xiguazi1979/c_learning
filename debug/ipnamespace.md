# linux上可以创建net
namespace，不同NS内的进程可以看到NS里的网口，NS间可以做网口直连或桥接

#!/bin/bash
ip netns add ns1
ip netns add ns2
ip link add veth1.1 type veth peer name veth2.2
ip link add veth1.2 type veth peer name veth2.3
ip link add veth1.3 type veth peer name veth2.4
ip link add veth1.4 type veth peer name veth2.1
ip link set veth1.1 netns ns1
ip link set veth1.2 netns ns1
ip link set veth1.3 netns ns1
ip link set veth1.4 netns ns1
ip link set veth2.1 netns ns2
ip link set veth2.2 netns ns2
ip link set veth2.3 netns ns2
ip link set veth2.4 netns ns2
ip netns exec ns1 ip addr add 192.168.1.1/24 dev veth1.1
ip netns exec ns1 ip addr add 192.168.1.2/24 dev veth1.2
ip netns exec ns1 ip addr add 192.168.1.3/24 dev veth1.3
ip netns exec ns1 ip addr add 192.168.1.4/24 dev veth1.4
ip netns exec ns2 ip addr add 192.168.1.21/24 dev veth2.1
ip netns exec ns2 ip addr add 192.168.1.22/24 dev veth2.2
ip netns exec ns2 ip addr add 192.168.1.23/24 dev veth2.3
ip netns exec ns2 ip addr add 192.168.1.24/24 dev veth2.4
ip netns exec ns1 ip link set veth1.1 up
ip netns exec ns2 ip link set veth2.2 up

ip netns exec ns1 ip link set veth1.2 up
ip netns exec ns1 ip link set veth1.3 up
ip netns exec ns1 ip link set veth1.4 up
ip netns exec ns2 ip link set veth2.3 up
ip netns exec ns2 ip link set veth2.4 up
ip netns exec ns2 ip link set veth2.1 up






sudo ip netns exec ns1 ./ctrl_eoam -i 1 -m 1 -a 1
sudo ip netns exec ns1 ./ctrl_eoam -i 2 -m 1 -a 1
sudo ip netns exec ns1 ./ctrl_eoam -i 3 -m 1 -a 1
sudo ip netns exec ns1 ./ctrl_eoam -i 4 -m 1 -a 1
sudo ip netns exec ns2 ./ctrl_eoam -i 1 -m 1 -a 1
sudo ip netns exec ns2 ./ctrl_eoam -i 2 -m 1 -a 1
sudo ip netns exec ns2 ./ctrl_eoam -i 3 -m 1 -a 1
sudo ip netns exec ns2 ./ctrl_eoam -i 4 -m 1 -a 1
