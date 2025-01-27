大家还知道怎么在一本很厚的词典查找一个单词吗？字典中的单词是按照“字典序”进行排序的，比如 code<pan<pancake 。如果我们要找一个单词，就要将字典从中间翻开，然后将这面单词跟想要找的单词比较。如果这面单词在需要寻找的单词之前，就将字典往后翻，否则就往前翻，直到找到准确的单词为止。
大家可以发现，越接近需要查询的单词，翻动书面的页数就越少。你肯定不会从第一页开始一面一面翻，逐个查看每个单词是否就是自己想要查的单词，这样做就太慢了。虽然实际情况不是那么精确，但是基本上使用了“二分思想”。
如果序列是有序的，就可以通过二分查找快速定位所需要的数据。除此之外，二分思想还能求出可行解的最值问题，比如想知道某款手机最高能多少楼高度摔下来而不会摔坏，使用二分的方式可以用最小实验次数就能得到结果（当然你需要准备好几个样品）。

# 一、二分查找
# 13.1 查找
## 题目描述
输入 $n$ 个不超过 $10^9$ 的单调不减的（就是后面的数字不小于前面的数字）非负整数 $a_1,a_2,\dots,a_{n}$，然后进行 $m$ 次询问。对于每次询问，给出一个整数 $q$，要求输出这个数字在序列中第一次出现的编号，如果没有找到的话输出 $-1$ 。
## 输入格式
第一行 $2$ 个整数 $n$ 和 $m$，表示数字个数和询问次数。
第二行 $n$ 个整数，表示这些待查询的数字。
第三行 $m$ 个整数，表示询问这些数字的编号，从 $1$ 开始编号。
## 输出格式
输出一行，$m$ 个整数，以空格隔开，表示答案。
## 样例 #1
### 样例输入 #1
```
11 3
1 3 3 3 5 7 9 11 13 15 15
1 3 6
```
### 样例输出 #1
```
1 2 -1
```
## 提示
数据保证，$1 \leq n \leq 10^6$，$0 \leq a_i,q \leq 10^9$，$1 \leq m \leq 10^5$
本题输入输出量较大，请使用较快的 IO 方式。

```cpp
#include<iostream>
#define MAXN 1000010
using namespace std;
int a[MAXN], m, n, q;
int find(int x) {
	int l = 1, r = n+1;
	while (l < r) {
		int mid = l+(r-l)/2;
		if (a[mid] >= x)   r=mid;
		else l = mid + 1;
	}
	if (a[l] == x)  return l;
	else return -1;
}
int main() {
	cin >>n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> q;
		cout << find(q) << " ";
	}
	return 0;
}
```
# 补充知识：STL中的lower_bound()和upper_bound()   头文件：algorithm
lower_bound(begin,end,val):在值有序的数组连续地址[begin,end)中找到第一个位置并返回其地址，使得val插入在这个前面，整个数组仍然保持有序。
upper_bound(begin,end,val):在值有序的数组连续地址[begin,end)中找到最后一个位置并返回其地址，使得val插入在这个前面，整个数组仍然保持有序。
简易理解：比较 lower_bound() 和 upper_bound() 的区别
lower_bound(value) 返回 第一个不小于 value 的元素（即 value 可能是返回的元素），它允许找到等于 value 的元素。
upper_bound(value) 返回 第一个大于 value 的元素，它不允许找到等于 value 的元素。
# 13.2 A-B 数对
## 题目背景
出题是一件痛苦的事情！
相同的题目看多了也会有审美疲劳，于是我舍弃了大家所熟悉的 A+B Problem，改用 A-B 了哈哈！
## 题目描述
给出一串正整数数列以及一个正整数 $C$，要求计算出所有满足 $A - B = C$ 的数对的个数（不同位置的数字一样的数对算不同的数对）。
## 输入格式
输入共两行。
第一行，两个正整数 $N,C$。
第二行，$N$ 个正整数，作为要求处理的那串数。
## 输出格式
一行，表示该串正整数中包含的满足 $A - B = C$ 的数对的个数。
## 样例 #1
### 样例输入 #1
```
4 1
1 1 2 3
```
### 样例输出 #1
```
3
```
## 提示
对于 $75\%$ 的数据，$1 \leq N \leq 2000$。
对于 $100\%$ 的数据，$1 \leq N \leq 2 \times 10^5$，$0 \leq a_i <2^{30}$，$1 \leq C < 2^{30}$。

# 法一、O(n log n)
```cpp
#include<cstdio>
#include<algorithm>
#define maxn 200010
using namespace std;
typedef long long LL;
LL a[maxn];
int n, c;
int main() {
	scanf("%d%d", &n, &c);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a, a + n);
	LL tot = 0;
	for (int i = 0; i < n; i++) {
		tot += upper_bound(a, a + n, a[i] + c) - lower_bound(a, a + n, a[i] + c);
	}
	printf("%lld", tot);
}
```

### 解释：
给定条件是我们需要计算所有满足 `A - B = C` 的数对 `(A, B)`。根据这个条件，可以将问题转化为：
- 对于每个元素 `A = a[i]`，我们需要查找 `B = a[j]`，使得 `a[i] - a[j] = C`，即 `a[j] = a[i] - C`。
因此，我们的目标是在数组中找出所有满足 `a[j] = a[i] - C` 的元素。
### 使用 `lower_bound` 和 `upper_bound`
1. **`lower_bound` 和 `upper_bound` 定义**：
   - `lower_bound(a, a + n, x)` 返回的是第一个大于等于 `x` 的元素的位置。
   - `upper_bound(a, a + n, x)` 返回的是第一个大于 `x` 的元素的位置。
2. **对于每个 `a[i]`，我们需要寻找 `a[j] = a[i] - c` 的位置**。为了查找这个值在数组中的出现位置，我们可以使用 `lower_bound` 和 `upper_bound` 来查找这个值的区间。
### `upper_bound` 和 `lower_bound` 的差值
假设我们要找的值是 `a[i] - c`（即 `B = a[i] - C`）：
- **`lower_bound(a, a + n, a[i] - c)`** 返回的是数组中第一个大于等于 `a[i] - c` 的位置。
- **`upper_bound(a, a + n, a[i] - c)`** 返回的是数组中第一个大于 `a[i] - c` 的位置。
对于满足 `a[j] = a[i] - C` 的所有 `j`，它们的位置就落在 `lower_bound` 和 `upper_bound` 之间。因此，`upper_bound - lower_bound` 的差值给出的是这个值出现的次数。
### 示例
假设我们有一个数组 `a = [1, 1, 2, 3]`，并且我们想查找满足 `a[i] - a[j] = 1` 的数对。
- 设 `c = 1`，即我们需要找 `a[j] = a[i] - 1`。
- 对于每个 `a[i]`，我们会进行以下查询：
  - 对于 `a[0] = 1`，我们需要查找 `a[j] = 0`。由于 `0` 不在数组中，`lower_bound(a, a + n, 0)` 和 `upper_bound(a, a + n, 0)` 都会返回指向第一个元素的迭代器，差值为 `0`。
  - 对于 `a[1] = 1`，同样，`a[j] = 0`，`upper_bound - lower_bound = 0`。
  - 对于 `a[2] = 2`，我们需要查找 `a[j] = 1`，它在数组中的位置是两个 `1`，所以 `upper_bound - lower_bound = 2`。
  - 对于 `a[3] = 3`，我们需要查找 `a[j] = 2`，它在数组中的位置是 `2`，所以 `upper_bound - lower_bound = 1`。
### 修正代码的部分：
```cpp
LL tot = 0;
for (int i = 0; i < n; i++) {
    tot += upper_bound(a, a + n, a[i] - c) - lower_bound(a, a + n, a[i] - c);
}
```
- 对于每个 `a[i]`，`upper_bound(a, a + n, a[i] - c)` 查找 `a[j] = a[i] - c` 在数组中的第一个大于该值的位置。
- `lower_bound(a, a + n, a[i] - c)` 查找第一个大于等于 `a[i] - c` 的位置。
这两个值的差值即为 `a[i] - c` 这个值在数组中出现的次数。
### 时间复杂度
- `lower_bound` 和 `upper_bound` 都是二分查找，时间复杂度是 `O(log n)`。
- 所以对于每个元素 `a[i]`，我们进行一次 `upper_bound` 和一次 `lower_bound`，总的时间复杂度是 `O(n log n)`。
### 总结
- `upper_bound` 和 `lower_bound` 用于查找指定元素的位置区间，通过这两个函数的差值可以高效地计算满足条件的数对个数。
- 时间复杂度为 `O(n log n)`，非常适合处理大数据量的情况。

# 法二、O(n)
```cpp
#include<cstdio>
#include<algorithm>
#define maxn 200010
using namespace std;
typedef long long LL;
LL a[maxn];
int n, c;
int main() {
	scanf("%d%d", &n, &c);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a, a + n);
	LL tot = 0;
	for (int i = 0, L = 0, R = 0; i < n; i++) {
		while (L < n && a[L] < a[i] + c) {
			L++;
		}
		while (R < n && a[R] <= a[i] + c) {
			R++;
		}
		tot += R - L;
	}
	printf("%lld", tot);
}
```

# 二、二分答案
# 13.3 EKO / 砍树
## 题目描述
伐木工人 Mirko 需要砍 $M$ 米长的木材。对 Mirko 来说这是很简单的工作，因为他有一个漂亮的新伐木机，可以如野火一般砍伐森林。不过，Mirko 只被允许砍伐一排树。
Mirko 的伐木机工作流程如下：Mirko 设置一个高度参数 $H$（米），伐木机升起一个巨大的锯片到高度 $H$，并锯掉所有树比 $H$ 高的部分（当然，树木不高于 $H$ 米的部分保持不变）。Mirko 就得到树木被锯下的部分。例如，如果一排树的高度分别为 $20,15,10$ 和 $17$，Mirko 把锯片升到 $15$ 米的高度，切割后树木剩下的高度将是 $15,15,10$ 和 $15$，而 Mirko 将从第 $1$ 棵树得到 $5$ 米，从第 $4$ 棵树得到 $2$ 米，共得到 $7$ 米木材。
Mirko 非常关注生态保护，所以他不会砍掉过多的木材。这也是他尽可能高地设定伐木机锯片的原因。请帮助 Mirko 找到伐木机锯片的最大的整数高度 $H$，使得他能得到的木材至少为 $M$ 米。换句话说，如果再升高 $1$ 米，他将得不到 $M$ 米木材。
## 输入格式
第 $1$ 行 $2$ 个整数 $N$ 和 $M$，$N$ 表示树木的数量，$M$ 表示需要的木材总长度。
第 $2$ 行 $N$ 个整数表示每棵树的高度。
## 输出格式
$1$ 个整数，表示锯片的最高高度。
## 样例 #1
### 样例输入 #1
```
4 7
20 15 10 17
```
### 样例输出 #1
```
15
```
## 样例 #2
### 样例输入 #2
```
5 20
4 42 40 26 46
```
### 样例输出 #2
```
36
```
## 提示
对于 $100\%$ 的测试数据，$1\le N\le10^6$，$1\le M\le2\times10^9$，树的高度 $\le 4\times 10^5$，所有树的高度总和 $>M$。

```cpp
#include<cstdio>
using namespace std;
#define maxn 1000010
typedef long long LL;
LL a[maxn], n, m;
bool P(int h) {
	LL tot = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] > h)  tot += a[i] - h;
	}
	return tot >= m;
}

int main() {
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	int L = 0, R = 1e9, ans, mid;
	while (L <= R) {
		if (P(mid = L + R >> 1))
			ans = mid, L = mid + 1;
		else
			R = mid - 1;
	}
	printf("%d", ans);
}
```

