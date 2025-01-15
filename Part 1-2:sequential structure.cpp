//2.1 
#include<iostream>
using namespace std;
int main() {
	int v_a = 5, v_yao = 8, distance = 100;
	double delta, ans;
	delta = v_yao - v_a;
	ans = distance / delta;
	//ans = 1.0*distance / (v_yao - v_a);
	cout << ans << endl;
	return 0;
}

//2.2
#include<iostream>
using namespace std;
int main() {
	int ans1;
	char ans2;
	ans1 = 'M' - 'A' + 1;
	ans2 = 'A' + 18 - 1;
	cout << ans1 << endl;
	cout << ans2 << endl;
	return 0;
}

ASCII表
0  NUL (null)          32  SPACE              64  @                96  `  
1  SOH (start of heading)  33  !                65  A                97  a
2  STX (start of text)    34  "                66  B                98  b
3  ETX (end of text)      35  #                67  C                99  c
4  EOT (end of transmission) 36  $                68  D               100  d
5  ENQ (enquiry)          37  %                69  E               101  e
6  ACK (acknowledge)      38  &                70  F               102  f
7  BEL (bell)             39  '                71  G               103  g
8  BS  (backspace)        40  (                72  H               104  h
9  TAB (horizontal tab)   41  )                73  I               105  i
10 LF  (line feed)        42  *                74  J               106  j
11 VT  (vertical tab)     43  +                75  K               107  k
12 FF  (form feed)        44  ,                76  L               108  l
13 CR  (carriage return)  45  -                77  M               109  m
14 SO  (shift out)        46  .                78  N               110  n
15 SI  (shift in)         47  /                79  O               111  o
16 DLE (data link escape) 48  0                80  P               112  p
17 DC1 (device control 1) 49  1                81  Q               113  q
18 DC2 (device control 2) 50  2                82  R               114  r
19 DC3 (device control 3) 51  3                83  S               115  s
20 DC4 (device control 4) 52  4                84  T               116  t
21 NAK (negative acknowledge) 53  5             85  U               117  u
22 SYN (synchronous idle) 54  6                86  V               118  v
23 ETB (end of block)     55  7                87  W               119  w
24 CAN (cancel)           56  8                88  X               120  x
25 EM  (end of medium)    57  9                89  Y               121  y
26 SUB (substitute)       58  :                90  Z               122  z
27 ESC (escape)           59  ;                91  [               123  {
28 FS  (file separator)   60  <                92  \               124  |
29 GS  (group separator)  61  =                93  ]               125  }
30 RS  (record separator) 62  >                94  ^               126  ~
31 US  (unit separator)   63  ?                95  _               127  DEL

//2.3
#include<iostream>
#include<cmath>
using namespace std;
#define PI 3.141593
int main() {
	int r1 = 4, r2 = 10;
	double V, l;
	V = 4.0 / 3 * PI * (r1 * r1 * r1 + r2 * r2 * r2);
	l = pow(V, 1.0 / 3);
	cout << (int)l << endl;
	return 0;
}

//2.4
#include<iostream>
#include<cmath>
using namespace std;
int main() {
	double a = 1, b = -100, c = 2400;
	double delta, ans;
	delta = pow(b, 2) - 4 * a * c;
	ans = (-b + sqrt(delta)) / (2 * a);
	cout << 110 - int(ans + 0.5) << endl; //int(ans + 0.5)意思是四舍五入到整数
	return 0;
}

//2.5
#include<iostream>
using namespace std;
int main() {
	int t, n;
	cin >> t >> n;
	cout << t * n << endl;
	return 0;
}

//2.6
#include<iostream>
using namespace std;
int main(){
  char ch,ans;
  cin>>ch;
  ans=ch-'a'+'A';//=ch-('a'-'A')=ch-32
  cout<<ans;
  return 0;
}

//2.7
#include<iostream>
using namespace std;
int main(){
    char a,b,c,dot,d;
    cin>>a>>b>>c>>dot>>d;
    cout<<d<<dot<<c<<b<<a<<endl;
    return 0;
}
//使用C风格
#include<cstdio>
int main(){
  char a,b,c,d;
  scanf("%c%c%c.%c",&a,&b,&c,&d);
  printf("%c.%c%c%c",d,c,b,a);
  return 0;
}

//2.8
#include<iostream>
using namespace std;
int main() {
	double t;
	int n;
	cin >> t >> n;
	cout << t / n <<" " << n * 2;
	return 0;
}

常见输入输出占位符
%d int
%nd 输入一个整数，不足n位，前面用空格补齐直到n位
%I64d long long类型
%f 读入一个float类型的带小数点的浮点数，输出float或double类型的浮点数
%lf 读入double类型的浮点数
%.nf 输出一个固定n位小数的浮点数
%0nd 输出一个整数，不足n位，前面用0补齐直到够n位
%c 一个char类型的字符
%s 一个字符串

//2.9
#include<cstdio>
using namespace std;
int main(){
  int a,b,c;
  scanf("%d %d",&a,&b);
  t=a;
  a=b;
  b=t;
  printf("%d %d",a,b);
  return 0;
}

//2.10
#include<cstdio>
using namespace std;
int main() {
	int a, b, c, d, e, f, delta;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	delta = (60 * c + d) - (60 * a + b);
	e = delta / 60;
	f = delta % 60;
	printf("%d %d", e, f);
	return 0;
}

//2.11
#include<cstdio>
using namespace std;
int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	printf("%d", a * 2 / 10 + b * 3 / 10 + c * 5 / 10);
	return 0;
}

//2.12
#include<cstdio>
#include<cmath>
using namespace std;
int main() {
	int s, v;
	scanf("%d%d", &s, &v);
	int t_walk = ceil(1.0 * s / v) + 10;
	int from_zero = 60 * (24 + 8) - t_walk;
	int hh = (from_zero / 60) % 24;
	int mm = from_zero % 60;
	printf("%02d:%02d\n", hh, mm);
	return 0;
}


