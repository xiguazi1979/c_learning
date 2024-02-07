## 二叉搜索树
https://blog.csdn.net/qq_28229519/article/details/126329923  
二叉查找树也称二叉树,是一种结合了二分查找策略的链接结构,众所周知,链式结构也称链表,它可以在不确定数据项个数的情况下存储数据项,那为什么又要使用树这种复杂的数据结构去存储呢?
为了更有效率的查找。
我们这样定义二叉查找树:
二叉树中的每个节点都包含两个子节点—左节点和右节点，其顺序按照如下规定确定:左节点的项在父节点的项前面，右节点的项在父节点的项后面。这种关系存在于每个有子节点的节点中。进一步而言，所有可以追溯其祖先回到一个父节点的左节点的项，都在该父节点项的前面;所有以一个父节点的右节点为祖先的项，都在该父节点项的后面。图中的树以这种方式储存单词。有趣的是，与植物学的树相反,该树的顶部被称为根( root)。
二叉树应有的功能是什么?
类型名	二叉查找树
类型操作:	
初始化树
确认树是否为空
确认树是否为满
能够知道树中的项数
在树中添加一个项
在树中删除一个项
在树中查找一个项
在树中访问一个项
清空树

## 例题：
### 1. binary1.c   宠物店
现在要开发一个宠物店的数据库,每一条数据都包含了宠物的名字和宠物的种类(宠物名不允许重复),要求能够快速查询,添加,访问,删除数据项
优点： 当需要比较不同的数据形式时，就不必重写整个AddNode ( )函数，只需重写Toleft ()和ToRight ()即可。
seekItem () 函数可以用递归的方式实现。但是，为了给读者介绍更多编程技巧，我们这次使用while循环处理树中从上到下的查找。
Traverse(const Tree *ptree,void (*pfun)(Item item)); 遍历函数的声明很精彩
gcc binary1.c binary1_main.c -o test
./test
enjoy

## 红黑树（一种平衡二叉树）
注意： kernel代码里的右旋逻辑和这里的右旋动画一致，但代码看的时候最好随手画个图，理解他的几个主要步骤。
材料里的右旋动画上方的图似乎是错的。旋转的核心是grandparent，GP的父只是个不会动的根最后指向新的child而已。
__rb_rotate_right(struct rb_node *node, struct rb_root *root)
调用者发现LL失衡后，设置其grandparent为pivot(支点)，作为此函数的第一个参数
其中node变量是支点，他要跟他的左子一起做一次右旋，root是树根

内部局部变量parent是GP的父, left是GP的做子（也就是调用者插入节点的父）。看着代码的每一行画两个图最容易理解。

https://www.cnblogs.com/crazymakercircle/p/16320430.html 这个讲算法很清楚，大约1小时学习。但是JAVA的。
AVL的比较：
由于这种严格的平衡条件，导致AVL需要花大量时间在调整上，AVL树一般使用场景在于查询场景， 而不是 增加删除 频繁的场景。
黑树(rbt)在查询速率和平衡调整中寻找平衡，放宽了树的平衡条件，从而可以用于 增加删除 频繁的场景。
红黑树是一种特化的AVL树（平衡二叉树）
红黑树是在1972年由Rudolf Bayer发明的，当时被称为平衡二叉B树（symmetric binary B-trees）.
在1978年被 Leo J. Guibas 和 Robert Sedgewick 修改为如今的“红黑树”.
RBTree是复杂的, 但它的最坏情况运行时间也是非常良好的,并且在实践中是高效的
它可以在O(log n)时间内做查找,插入和删除

红色属性 说明，红色节点的孩子，一定是黑色。 但是，RBTree 黑色节点的孩子，可以是红色，也可以是黑色，具体如下图。
叶子属性 说明， 叶子节点可以是空nil ，AVL的叶子节点不是空的，具体如下图。
RBtree在avl的节点上，增加了 颜色属性的 数据，相当于 增加了空间的消耗。 通过颜色属性的增加， 换取，后面平衡操作的次数 减少。

rbt 的 左子树和右子树的黑节点的层数是相等的
红黑树的平衡条件，不是以整体的高度来约束的，而是以黑色 节点的 高度，来约束的。
所以称红黑树这种平衡为黑色完美平衡。
去掉 rbt中的红色节点，会得到 一个四叉树， 从根节点到每一个叶子，高度相同，就是rbt的root到叶子的黑色路径长度。
任何不平衡都会在三次旋转之内解决
红黑树的算法时间复杂度和AVL相同，但统计性能比AVL树更高
适用性：AVL查找效率高
如果你的应用中，查询的次数远远大于插入和删除，那么选择AVL树，如果查询和插入删除次数几乎差不多，应选择红黑树。

https://zhuanlan.zhihu.com/p/78152265 
1．节点分为红色或者黑色；（颜色属性）
2．根节点必为黑色；（根属性）
3．叶子节点都为黑色，且为null；（叶子属性）
4．连接红色节点的两个子节点都为黑色（红黑树不会出现相邻的红色节点）；（红色属性）
5．从任意节点出发，到其每个叶子节点的路径中包含相同数量的黑色节点；（黑色属性）黑色属性，可以理解为平衡特征， 如果满足不了平衡特征，就要进行平衡操作
6．新加入到红黑树的节点为红色节点；原因参照最后一条原则： 红色破坏原则的可能性最小，如果是黑色, 很可能导致这条支路的黑色节点比其它支路的要多1，破坏了平衡。

https://zhuanlan.zhihu.com/p/584295999 
红黑树的基本定义：

根节点是黑色的；
叶节点是黑色的；
红色节点不能有红色子节点；
从根节点出发，到每一叶节点的路径上，黑节点的数量相同；
节点可以为红色和黑色；

红黑树不是严格意义上的平衡树，但是红黑树能够保证从根节点到叶节点的最长路径小于最短路径的两倍，也就是Lmax < 2*Lmin，因此红黑树是一种相对而言比较平衡的树，在数据比较随机的情况下，能够取得比较好的平衡性

红黑树的节点有三个指针，父节点、左儿子、右儿子，这种节点也是算法导论里面给出的红黑树的节点定义。
不使用父节点会导致大量的递归过程，对性能损耗应该是很大的。

红黑树的插入过程：

插入的节点首先会被涂成红色的，插入过程中按照二叉搜索树的插入节点的过程插入节点。然后进行平衡处理
红黑树在插入过程中的平衡性，主要是通过旋转和递归涂黑处理。

红黑树的删除同样容易导致红黑树的不平衡，因此需要进行调整。如果删除的节点是红色的，那么不会破坏红黑树的性质，如果删除的节点是黑色的，那么就需要进行平衡处理。
删除完节点之后，需要进行调整，因为删除过程中，如果删去了黑色的节点，会破坏红黑树的性质，也就是从root到叶节点黑高的一致性。
有对红黑树进行测试过的说红黑树与AVL树的性能差不多，但是红黑树在组织方式更加复杂，不过STL采用红黑树作为map、set底层结构，必然是考虑到了性能、实现等等。

### kernel RBtree
https://elixir.bootlin.com/linux/v5.10/source/include/linux/rbtree.h#L49 (it has RCU, difficult to try, but rbtree.c has good comment to study for rbtree.c  So in trial we use v3.0)

https://zhuanlan.zhihu.com/p/183006935 （内核RB tree）
建议看完基本的RB tree教程后gdb调试一下插入两个数3,2 即可理解代码
巧妙之处是使用成员rb_parent_color同时存储两种数据，一是其双亲结点的地址，另一是此结点的着色。
提问：64位linux中sizeof(long)对齐的是32位还是64位？见c_basics的endian部分
struct rb_node
{
	unsigned long  rb_parent_color;
#define	RB_RED		0
#define	RB_BLACK	1
	struct rb_node *rb_right;
	struct rb_node *rb_left;
} __attribute__((aligned(sizeof(long))));

（1）、从内核中拷贝源文件：

$ mkdir redblack
$ cd redblack/
$ cp ../../lib/rbtree.c .
$ cp ../../include/linux/rbtree.h .
（2）、修改源文件：

a、C文件rbtree.c

修改包含头文件的代码

//删除以下两行代码
#include <linux/rbtree.h>
#include <linux/module.h>
//新增以下代码，即包含当前目录中的头文件rbtree.h
#include "rbtree.h"
删除所有的EXPORT_SYMBOL宏

EXPORT_SYMBOL(rb_insert_color);
EXPORT_SYMBOL(rb_erase);
EXPORT_SYMBOL(rb_augment_insert);
EXPORT_SYMBOL(rb_augment_erase_begin);
EXPORT_SYMBOL(rb_augment_erase_end);
EXPORT_SYMBOL(rb_first);
EXPORT_SYMBOL(rb_last);
EXPORT_SYMBOL(rb_next);
EXPORT_SYMBOL(rb_prev);
EXPORT_SYMBOL(rb_replace_node);
b、头文件rbtree.h

删除包含头文件的代码，并添加三个宏定义

//删除以下两行代码
#include <linux/kernel.h>
#include <linux/stddef.h>
 
/* ../include/linux/stddef.h */
#undef NULL
#if defined(__cplusplus)
#define NULL 0
#else
#define NULL ((void *)0)
#endif
 
/*../include/linux/stddef.h */
#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)
 
/* ../include/linux/kernel.h */
#define container_of(ptr, type, member) ({			\
	const typeof( ((type *)0)->member ) *__mptr = (ptr);	\
	(type *)( (char *)__mptr - offsetof(type,member) );})

（3）、示例代码
c_tree\kernelRBtree\kernelRBtree_example.c

编译并执行：

$ gcc rbtree.c test.c -o test
gdb ./test
set args 5
run

richard@tanglinux:~/algorithm/redblack$ ./test 10
Please enter 10 integers:
23
4
56
32
89
122
12
21
45
23
The 23 already exists.
 
the first test
4 12 21 23 32 45 56 89 122 
 
the second test
4 12 23 32 45 56 89 122
使用的精华在：
my_insert()
    /* Add new node and rebalance tree. */
    rb_link_node(&data->my_node, parent, tmp); // simply search out then insert
    rb_insert_color(&data->my_node, root); // rebalance
## AVL树
AVL树应该用的不多，主要是需要进行大量的递归计算树的高度，

## AA树
AA树是Arne Andersson教授在他的论文"Balanced search trees made simple"中介绍的一个红黑树变种，设计的目的是减少RB树考虑的cases
