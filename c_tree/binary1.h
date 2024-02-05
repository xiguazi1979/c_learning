//tree.h	//二叉树接口头文件
#ifndef _TREE_H_
#define _TREE_H_

#include <stdbool.h>	//可替换成enum bool {false,true};
/* 根据具体情况定义Item */
#define SLEN 20
#define MAXITEMS    100
typedef struct Item
{
    /**********这里可以是任何想要存储的东西**************/
    char petname[SLEN];	//宠物名
    char petkind[SLEN];	//宠物种类
}Item;	//以后如果需要修改存储的数据类型,可以直接在这里修改就好
typedef struct trnode
{
    Item item;	//这是我们刚刚定义的数据
    struct trnode *left;	//该节点指向的左子树
    struct trnode *right;	//该节点指向的右子树
}Trnode;	//将需要存储的数据和两个指向子树的指针合起来构成节点
typedef struct tree
{
    Trnode *root;	//指向根节点的指针
    int size;		//存储树的节点数(大小)
}Tree;	//存储大小以方便后面判断树是否为空树

/* 自定义接口函数原型 */

/*************************************
*函数名:InitializeTree
*功  能:初始化一棵树为空
*参  数:指向树的指针 Tree *ptree
*返  回:void
*************************************/
void InitializeTree(Tree *ptree);

/*************************************
*函数名:TreeIsEmpty
*功  能:确定树是否为空
*参  数:指向树的指针 const Tree *ptree
*返  回:树为空返回true(1),否则返回false(0)
*************************************/
bool TreeIsEmpty(const Tree *ptree);

/*************************************
*函数名:TreeIsFull
*功  能:确定树是否为满
*参  数:指向树的指针 const Tree *ptree
*返  回:树为满返回true(1),否则返回false(0)
*************************************/
bool TreeIsFull(const Tree *ptree);

/*************************************
*函数名:TreeItemCount
*功  能:返回树的节点数(项数)
*参  数:指向树的指针 const Tree *ptree
*返  回:树的项数int
*************************************/
int TreeItemCount(const Tree *ptree);

/*************************************
*函数名:	AddItem
*功  能:在树中添加一个项
*参  数:指向待添加项的指针const Item *pi
*	   指向一个已初始化树的指针Tree *ptree  
*返  回:成功添加返回true,否则返回false
*************************************/
bool AddItem(const Item *pi,Tree *ptree);

/*************************************
*函数名:InTree
*功  能:在树中查找一个项
*参  数:指向待查找项的指针const Item *pi
*      指向树的指针 const Tree *ptree
*返  回:找到返回true,否则返回false
*************************************/
bool InTree(const Item *pi,const Tree *ptree);

/*************************************
*函数名:DeleteItem
*功  能:在树中删除一个项
*参  数:指向待删除项的指针const Item *pi
*      指向树的指针Tree *ptree
*返  回:删除成功返回true(1),否则返回false(0)
*************************************/
bool DeleteItem(const Item *pi,Tree *ptree);

/*************************************
*函数名:Traverse
*功  能:把树中的每一项都应用于另一个函数
*参  数:指向树的指针 const Tree *ptree
*      函数指针void(*pfun)(Item item)
*返  回:void
*************************************/
void Traverse(const Tree *ptree,void (*pfun)(Item item));

/*************************************
*函数名:DeleteAll
*功  能:删除树中的所有内容(释放内存)
*参  数:指向树的指针Tree *ptree
*返  回:void
*************************************/
void DeleteAll(Tree *ptree);

#endif
