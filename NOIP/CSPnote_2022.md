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

# 网上的经验总结
## https://www.cnblogs.com/ahawzlc/p/15418146.html 
。。。
三、比赛策略
本条目针对 CSP/NOIP 常见题型。
大模拟：权衡时间，取性价比高的部分分。
数学、规律题：证明 or 猜测。（如小凯的疑惑。）
DP、图论：重中之重，属于主要做的题目。
永远记住暴力和骗分。
在空余的时间对拍、自造大样例确保程序正确性。
最后 30min 检查程序是否正确提交。
四、考试状态
CSP-S2 是下午比赛，因此中午不能吃太饱、建议小睡一会。
考试时允许带食品，建议巧克力。
“厕所是 OIer 灵感的源泉。”洗手间可以让人冷静下来。
一定合理安排时间，不能炸心态，不能死磕一题。

# CSP-S题型筛选
2023题目详解：
https://zhuanlan.zhihu.com/p/663683037 
1. BFS 枚举
2. 组合
3. x
4. 图

# 省选题型-为全国统一
https://ac.nowcoder.com/acm/archive/noisx 
https://blog.csdn.net/qq_39565901/article/details/115920151 
https://zhuanlan.zhihu.com/p/613610454 
https://www.luogu.com.cn/training/148821#problems 
https://www.luogu.com.cn/training/8436 