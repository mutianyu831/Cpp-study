我们之前已经研究过很多算法了！比如，二分法可以用来“给定单调函数，求零点”；冒泡排序可以用来“给定一个数组，将其排序后输出”……你已经知道算法很有用，接下来要学习的数据结构，也一样很有用！初学数据结构，您可能会觉得无从下手；不过不用担心，本书会用很多生活中实际存在的例子来解释这些数据结构。
比如，在商场里面排队结账，或者在网上“秒杀”商品，差别很大；但它们都遵循着相同的规则——讲“先来后到”。早来的，就早买到商品；晚来的，就晚买到商品，甚至可能买不到商品。可以利用“先来后到”这一规则，把这两种排队模式统一起来——它们都是“队列”，都可以用队列这一数据结构来模拟。然后建模，编写计算机程序解决这些问题。
这一章，先开始学习线性表。线性表是最简单、最基本的一种数据结构，一个线性表示多个具有相同类型数据“串在一起”，每个元素有前驱（前一个元素）后继（后一个元素）。根据不同的特性，线性表也分为栈、队列、链表等等。因为这些特性，数据结构可以解决不同种类的问题。

# 一、数组
---
## 可变长度数组：头文件<vector>
使用方法：
1）vector<int>v(N,i)  建立一个可变长度数组v，内部元素类型为int，该变量数组最开始有N个元素，每个元素初始化为i。可以省略i，默认值为0，也可以把(N,i)同时省略，此时长度为0，内部元素类型也可以换成其他类型如double。
2）v.size()  返回数组v的长度
3）v.push_back(a) 将元素a插入到数组v的末尾，并增加数组的长度
4）v.resize(n,m) 重新调整数组大小为n，如果n比原来小，则删除多余的信息；如果n比原来大，则新增的部分都初始化为m，其中m可以省略
5）vector<int>::iterator it  定义一个名字叫作it的迭代器
6）v.begin() 返回数组v的首元素（v[0]）的指针（迭代器）
7）v.end()  返回数组v首元素末尾的下一个元素的指针（迭代器），这个指针类似于空指针，不指向任何元素
除了使用数组下标，还能通过“迭代器”来访问数组中的元素。迭代器类似于指针但并不能划等号，这里it可以认为是一个指向vector中元素的指针
it可以++或--变成前一个或后一个元素的指针，也能和指针一样用*it取该指针中的元素
由于迭代器和指针在表现方式上很接近，所以v[i]和 *(v.begin(+i))是一样的，都是取对应元素的值
然而，竞赛中经常只把vector当作普通的可变数组来使用，比较少用到迭代器
---
# 15.1询问学号
## 题目描述
有 $n(n \le 2 \times 10^6)$ 名同学陆陆续续进入教室。我们知道每名同学的学号（在 $1$ 到 $10^9$ 之间），按进教室的顺序给出。上课了，老师想知道第 $i$ 个进入教室的同学的学号是什么（最先进入教室的同学 $i=1$），询问次数不超过 $10^5$ 次。
## 输入格式
第一行 $2$ 个整数 $n$ 和 $m$，表示学生个数和询问次数。
第二行 $n$ 个整数，表示按顺序进入教室的学号。
第三行 $m$ 个整数，表示询问第几个进入教室的同学。
## 输出格式
输出 $m$ 个整数表示答案，用换行隔开。
## 样例 #1
### 样例输入 #1
```
10 3
1 9 2 60 8 17 11 4 5 14
1 5 9
```
### 样例输出 #1
```
1
8
5
```

```cpp
#include<iostream>
#include<vector>
using namespace std;
int n, m, tmp;
int main() {
	vector<int> stu;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		stu.push_back(tmp);
	}
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		cout << stu[tmp - 1] << endl;
	}
	return 0;
}
```

# 15.2 寄包柜
## 题目描述
超市里有 $n(1\le n\le10^5)$ 个寄包柜。每个寄包柜格子数量不一，第 $i$ 个寄包柜有 $a_i(1\le a_i\le10^5)$ 个格子，不过我们并不知道各个 $a_i$ 的值。对于每个寄包柜，格子编号从 1 开始，一直到 $a_i$。现在有 $q(1 \le q\le10^5)$ 次操作：
- `1 i j k`：在第 $i$ 个柜子的第 $j$ 个格子存入物品 $k(0\le k\le 10^9)$。当 $k=0$ 时说明清空该格子。
- `2 i j`：查询第 $i$ 个柜子的第 $j$ 个格子中的物品是什么，保证查询的柜子有存过东西。
已知超市里共计不会超过 $10^7$ 个寄包格子，$a_i$ 是确定然而未知的，但是保证一定不小于该柜子存物品请求的格子编号的最大值。当然也有可能某些寄包柜中一个格子都没有。
## 输入格式
第一行 2 个整数 $n$ 和 $q$，寄包柜个数和询问次数。
接下来 $q$ 个行，每行有若干个整数，表示一次操作。
## 输出格式
对于查询操作时，输出答案，以换行隔开。
## 样例 #1
### 样例输入 #1
```
5 4
1 3 10000 118014
1 1 1 1
2 3 10000
2 1 1
```
### 样例输出 #1
```
118014
1
```

```cpp
#include<iostream>
#include<vector>
using namespace std;
int n, q, opt, i, j, k;
int main() {
	cin >> n >> q;
	vector<vector<int>>locker(n + 1);
	while (q--) {
		cin >> opt;
		if (opt == 1) {
			cin >> i >> j >> k;
			if (locker[i].size() < j + 1)
				locker[i].resize(j + 1);
			locker[i][j] = k;
		}
		else {
			cin >> i >> j;
			cout << locker[i][j] << endl;
		}
	}
	return 0;
}
```

## 数组复杂度是O(1)，但整段移位操作（在中间插入删除数据）或搜索指定元素（如果没有排序），时间复杂度是O(n)。

# 二、栈
## 15.3 洗盘子
