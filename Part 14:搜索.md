我们在之前的章节介绍了暴力枚举策略，将所有可能的情况都枚举一遍以获得最优解，但是枚举全部元素的效率如同愚翁移山，无法应付数据范围稍大的情形。本章在暴力枚举的基础上介绍了搜索算法，包括深度优先搜索和广度优先搜索，从起点开始，逐渐扩大寻找范围，直到找到需要的答案为止。
严格来说，搜索算法也算是一种暴力枚举策略，但是其算法特性决定了效率比直接的枚举所有答案要高，因为搜索可以跳过一些无效状态，降低问题规模。在算法竞赛中，如果选手无法找到一种高效求解的方法（比如贪心、递推、动态规划、公式推导等），使用搜索也可以解决一些规模较小的情况；而有的任务就是必须使用搜索来完成，因此这是相当重要的策略。

# 一、深度优先搜索与回溯法
## 模板
```cpp
void dfs(int k) {
	if (所有空已经填完了) {
		判断最优解 / 记录答案;
		return;
	}
	for(枚举这个空能填的选项)
		if (这个选项是合法的) {
			记录下这个空(保存现场);
			dfs(k + 1);
			取消这个空(恢复现场)；
		}
}
```
## 14.1 四阶数独
```cpp
#include<cstdio>
#include<iostream>
using namespace std;
#define size 5
int a[size * size], n = 4 * 4, ans = 0;
int b1[size][5], b2[size][5], b3[size][5];
void dfs(int x) {
	if (x > n) {
		ans++;
		for (int i = 1; i <= n; i++) {
			printf("%d ", a[i]);
			if (i % 4 == 0) puts(" ");
		}
		puts(" ");
		return;
	}
	int row = (x - 1) / 4 + 1;
	int col = (x - 1) % 4 + 1;
	int block = (row - 1) / 2 * 2 + (col - 1) / 2 + 1;
	for (int i = 1; i <= 4; i++) {
		if (b1[row][i] == 0 && b2[col][i] == 0 && b3[block][i] == 0) {
			a[x] = i;
			b1[row][i] = 1; b2[col][i] = 1; b3[block][i] = 1;
			dfs(x + 1);
			b1[row][i] = 0; b2[col][i] = 0; b3[block][i] = 0;
		}
	}
}

int main() {
	dfs(1);
	printf("%d", ans);
	return 0;
}
```

# 14.2 八皇后 Checker Challenge
## 题目描述
一个如下的 $6 \times 6$ 的跳棋棋盘，有六个棋子被放置在棋盘上，使得每行、每列有且只有一个，每条对角线（包括两条主对角线的所有平行线）上至多有一个棋子。
![](https://cdn.luogu.com.cn/upload/image_hosting/3h71x0yf.png)
上面的布局可以用序列 $2\ 4\ 6\ 1\ 3\ 5$ 来描述，第 $i$ 个数字表示在第 $i$ 行的相应位置有一个棋子，如下：
行号 $1\ 2\ 3\ 4\ 5\ 6$
列号 $2\ 4\ 6\ 1\ 3\ 5$
这只是棋子放置的一个解。请编一个程序找出所有棋子放置的解。  
并把它们以上面的序列方法输出，解按字典顺序排列。  
请输出前 $3$ 个解。最后一行是解的总个数。
## 输入格式
一行一个正整数 $n$，表示棋盘是 $n \times n$ 大小的。
## 输出格式
前三行为前三个解，每个解的两个数字之间用一个空格隔开。第四行只有一个数字，表示解的总数。
## 样例 #1
### 样例输入 #1
```
6
```
### 样例输出 #1
```
2 4 6 1 3 5
3 6 2 5 1 4
4 1 5 2 6 3
4
```
## 提示
【数据范围】  
对于 $100\%$ 的数据，$6 \le n \le 13$。

```cpp
#include<cstdio>
using namespace std;
#define maxn 100
int a[maxn], n, ans=0;
int b1[maxn], b2[maxn], b3[maxn];
void dfs(int x) {
	if (x > n) {
		ans++;
		if (ans <= 3) {
			for (int i = 1; i <= n; i++)
				printf("%d ", a[i]);
			puts(" ");
		}
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (b1[i] == 0 && b2[x+i] == 0 && b3[x-i+15] == 0) {
			a[x] = i;
			b1[i] = 1; b2[x + i] = 1; b3[x - i + 15] = 1;
			dfs(x + 1);
			b1[i] = 0; b2[x + i] = 0; b3[x - i + 15] = 0;
		}
	}
}

int main() {
	scanf("%d", &n);
	dfs(1);
	printf("%d", ans);
	return 0;
}
```

# 14.3 kkksc03考前临时抱佛脚
## 题目背景
kkksc03 的大学生活非常的颓废，平时根本不学习。但是，临近期末考试，他必须要开始抱佛脚，以求不挂科。
## 题目描述
这次期末考试，kkksc03 需要考 $4$ 科。因此要开始刷习题集，每科都有一个习题集，分别有 $s_1,s_2,s_3,s_4$ 道题目，完成每道题目需要一些时间，可能不等（$A_1,A_2,\ldots,A_{s_1}$，$B_1,B_2,\ldots,B_{s_2}$，$C_1,C_2,\ldots,C_{s_3}$，$D_1,D_2,\ldots,D_{s_4}$）。
kkksc03 有一个能力，他的左右两个大脑可以同时计算 $2$ 道不同的题目，但是仅限于同一科。因此，kkksc03 必须一科一科的复习。
由于 kkksc03 还急着去处理洛谷的 bug，因此他希望尽快把事情做完，所以他希望知道能够完成复习的最短时间。
## 输入格式
本题包括 $5$ 行数据：第 $1$ 行，为四个正整数 $s_1,s_2,s_3,s_4$。
第 $2$ 行，为 $A_1,A_2,\ldots,A_{s_1}$ 共 $s_1$ 个数，表示第一科习题集每道题目所消耗的时间。
第 $3$ 行，为 $B_1,B_2,\ldots,B_{s_2}$ 共 $s_2$ 个数。
第 $4$ 行，为 $C_1,C_2,\ldots,C_{s_3}$ 共 $s_3$ 个数。
第 $5$ 行，为 $D_1,D_2,\ldots,D_{s_4}$ 共 $s_4$ 个数，意思均同上。
## 输出格式
输出一行,为复习完毕最短时间。
## 样例 #1
### 样例输入 #1
```
1 2 1 3		
5
4 3
6
2 4 3
```
### 样例输出 #1
```
20
```
## 提示
$1\leq s_1,s_2,s_3,s_4\leq 20$。
$1\leq A_1,A_2,\ldots,A_{s_1},B_1,B_2,\ldots,B_{s_2},C_1,C_2,\ldots,C_{s_3},D_1,D_2,\ldots,D_{s_4}\leq60$。

```cpp
#include<iostream>
#include<algorithm>
using namespace std;
int nowtime, maxtime, sum;
int ans, maxdeep;
int s[4], a[21];
void dfs(int x) {
	if (x > maxdeep) {
		maxtime = max(maxtime, nowtime);
		return;
	}
	if (nowtime + a[x] <= sum / 2) {
		nowtime += a[x];
		dfs(x + 1);
		nowtime -= a[x];
	}
	dfs(x + 1);
}

int main() {
	cin >> s[0] >> s[1] >> s[2] >> s[3];
	for (int i = 0; i < 4; i++) {
		nowtime = 0;
		maxdeep = s[i];
		sum = 0;
		for (int j = 1; j <= s[i]; j++) {
			cin >> a[j];
			sum += a[j];
		}
		maxtime = 0;
		dfs(1);
		ans += (sum - maxtime);
	}
	cout << ans;
	return 0;
}
```

# 二、广度优先搜索
## 模板
```cpp
Q.push(初始状态);              //初始状态入队
while (!Q.empty()) {
	State u = Q.front();       //取出队首
	Q.pop();
	for (枚举所有可扩展状态)       //找到u的所有可达状态
		if (是合法)                //v需要满足某些条件，如未访问过、未在队内等
			Q.push(v);             //入队(同时可能需要维护某些必要信息)
}
```
# 14.4 马的遍历
## 题目描述
有一个 $n \times m$ 的棋盘，在某个点 $(x, y)$ 上有一个马，要求你计算出马到达棋盘上任意一个点最少要走几步。
## 输入格式
输入只有一行四个整数，分别为 $n, m, x, y$。
## 输出格式
一个 $n \times m$ 的矩阵，代表马到达某个点最少要走几步（不能到达则输出 $-1$）。
## 样例 #1
### 样例输入 #1
```
3 3 1 1
```
### 样例输出 #1
```
0    3    2    
3    -1   1    
2    1    4
```
## 提示
### 数据规模与约定
对于全部的测试点，保证 $1 \leq x \leq n \leq 400$，$1 \leq y \leq m \leq 400$。

```cpp
#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
#define maxn 310
struct coord {
	int x, y;
};
queue<coord>Q;
int ans[maxn][maxn];
int walk[8][22] = { {2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1} };
int main() {
	int n, m, sx, sy;
	memset(ans, -1, sizeof(ans));
	cin >> n >> m >> sx >>sy;
	coord tmp = { sx,sy };
	Q.push(tmp);
	ans[sx][sy] = 0;
	while (!Q.empty()) {
		coord u = Q.front();
		int ux = u.x, uy = u.y;
		Q.pop();
		for (int k = 0; k < 8; k++) {
			int x = ux + walk[k][0], y = uy + walk[k][1];
			int d = ans[ux][uy];
			if (x<1 || x>n || y<1 || y>m || ans[x][y] != -1)
				continue;
			ans[x][y] = d + 1;
			coord tmp = { x,y };
			Q.push(tmp);
		}
	}

	for (int i = 1; i <= n; i++, puts(""))
		for (int j = 1; j <= m; j++)
			printf("%-5d", ans[i][j]);
	return 0;
}
```

