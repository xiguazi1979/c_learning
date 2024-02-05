# 环境设置
在考试之前，如无特殊限制，可做如下准备
读上机指南
按照指南要求：
    创文件夹，如 D:\NOIP\src\考号\题名 （考号20081115  提名：timu1
    创源文件，名字如 题名.cpp （一定要设置 查看-》文件扩展名）
    建立程序模板：

#include <bits/stdc++.h>
using namespace std;
int a,b;
int main()
{
//	freopen("timu1.in", "r", stdin);
//	freopen("timu1.out", "w", stdout);
	cin >> a >> b;
	cout << a + b;

//	fclose(stdin);
//	fclose(stdout);
	return 0;	
} 

    保存源文件
    编译调试
    按要求提交源文件

# 语言技巧
## #define
#define INF 0x7x    x   FFFFFFF
## #ifdef DEBUG加入调试信息

# C++常用头文件与库函数
## 乘方，开方，绝对值 <math.h>
//平方 pow()
int a = pow(4,2);// 4的平方=16
//开方
int b = pow(4,0.5);// 4的平方根=2
int c = sqrt(4);// 4的平方根=2
//整数绝对值
int c = abs(b-c);
//浮点数绝对值
double d = fabs(b-c);