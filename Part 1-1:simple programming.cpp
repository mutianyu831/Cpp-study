//1.1 程序设计目标和流程
#include<iostream>
using namespace std;
int main() {
	cout << "I love lougu!";
	return 0;
}

#include<iostream>
using namespace std;
int main(){
  cout<<2+4<<" "<<10-2-4;      //输出 6 4
  return 0;
}

//1.2简单数学运算
#include<iostream>
using namespace std;
int main() {
	cout << 14 / 4 << endl;   //endl换行
	cout << 14 / 4 * 4 << endl;
	cout << 14 - 14 / 4 * 4 << endl;
	// cout<<14%4<<endl;
	return 0;
}
//输出  3
//      12
//      2

#include<iostream>
using namespace std;
int main() {
	cout << "500.0/3"<<endl;  //输出166.667
	return 0;
}

数学函数
double sin(double x)
double cos(double x)
double exp(double x)  e的x次幂
double log(double x)
double pow(double x,double y)
double sqrt(double x)
double fabs(double x)
double ceil(double x)  上取整
double floor(double x) 下取整

//1.3变量与常量
#include<iostream>
using namespace std;
int main() {
	int balance =100;
	balance += 10;
	cout << balance << endl;
	balance -= 20;
	cout << balance << endl;
	balance = 0;
	cout << balance << endl;
	return 0;
}
//输出 110
//     90
//     0


//求圆的周长、面积、球的体积
#include<iostream>
#include<cmath>
using namespace std;
int main() {
	double r = 5;
	const double PI = 3.141593;// #define PI 3.141593
	cout << 2 * PI * r << endl;
	cout << PI * r * r << endl;
	cout << 4.0 / 3 * PI * pow(r, 3) << endl;
	return 0;
}

//猴子吃桃
#include<iostream>
#include<cmath>
using namespace std;
int main() {
	int num = 1;
	num = (num + 1) * 2;
	num = (num + 1) * 2;
	num = (num + 1) * 2;
	cout << num << endl;
	return 0;
}

//评测机队列
//8台评测机30min可以评完，10台评测机6min可以评完，问几台评测机可以在10分钟时评完
#include<iostream>
using namespace std;
int main() {
	int n1 = 8, t1 = 30, n2 = 10, t2 = 6;
	int t3 = 10;
	double inc_rate = (1.0 * n1 * t1 - n2 * t2) / (t1 - t2);
	double init_num = n2 * t2 - inc_rate * t2;
	double ans = (init_num + t3 * inc_rate) / t3;
	cout << ans;
	return 0;
}

//Part 1-1:Introduction to Language end
