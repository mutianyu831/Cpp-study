分支结构程序设计
//3.1
#include<iostream>
using namespace std;
int main(){
  int a,b;
  cin>>a>>b;
  cout<<(a<b)<<' ';
  cout<<(a>=b)<<' ';
  cout<<(a!=b)<<endl;
  return 0;
}

//3.2数的性质
#include<iostream>
using namespace std;
int main(){
    int x;
    bool p1,p2;
    cin>>x;
    p1=x%2==0;
    p2=4<x&&x<=12;
    cout<<(p1&&p2)<<' ';
    cout<<(p1||p2)<<' ';
    cout<<(p1^p2)<<' ';
    cout<<(!p1&&!p2)<<' ';
}

C++中几种逻辑运算符
  与：&
  或：||
  异或：^
  非：！
  
//3.3闰年判断
#include<iostream>
using namespace std;
int main(){
    int y;
    cin>>y;
    if(y%400==0||(y%4==0&&y%100!=0)) cout<<"1";
    else cout<<"0";
    return 0;
}

//3.4
#include<iostream>
using namespace std;
int main(){
    int c;
    cin>>c;
    if(c==0||c==1){
        cout<<"Today, I ate "<<c<<" apple.";
    }
    else{
        cout<<"Today, I ate "<<c<<" apples.";
    }
}

//3.5
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(5*n>(11+3*n)){
        cout<<"Luogu";
    }
    else{
        cout<<"Local";
    }
}

//3.6小洛机器人
#include<iostream>
using namespace std;
int main(){
  char opt;
  cin>>opt;
  switch(opt){
  case'G':cout << "Hello,my master!"<<end;
  case'N':cout << "I'm Xiaoluo."<<endl;
          break;
  case'S':cout<< "Teinei teinei teinei~"<<endl;
          break;
  case'B':case'Q':
      cout<<"Bye bye!"<<endl;
      break;
  default: cout<,"Sorry.."<<endl;
  }
  return 0;
}

//3.7
#include<iostream>
using namespace std;
int main(){
    double m,h,BMI;
    cin>>m>>h;
    BMI=m/h/h;
    if(BMI<18.5)   cout<<"Underweight";
    else if(BMI<24)   cout<<"Normal";
    else{
        cout <<BMI <<endl;
        cout<<"Overweight"<<endl;
        
    }
    return 0;
}

//3.8
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    if(a >= b){
        swap(a,b);
    }
    if(b >= c){
        swap(b,c);
    }
    if(a >= b){
        swap(a,b);
    }
    cout<<a<<" "<<b<<" "<<c;
    return 0;
}

//3.9
#include<iostream>
using namespace std;
int main(){
    int y,m;
    cin>>y>>m;
    switch(m){
        case 1:case 3:case 5: case 7:case 8:case 10: case 12:
            cout<<31<<endl; break;
        case 4:case 6:case 9:case 11:
            cout << 30 << endl; break;
        case 2:
            if(!(y%400)||!(y%4)&&y%100)
                cout <<29 <<endl;
            else
                cout << 28 << endl;
            break;
        default: break;
    }
    return 0;
}

//3.10
#include<iostream>
using namespace std;
int main() {
    int t1, t2, maxtime = 8, maxday = 0, s;
    for (int i = 1; i <= 7; i++) {
        cin >> t1 >> t2;
        s = t1 + t2;
        if (s > maxtime) {
            maxtime = s;
            maxday = i;
        }
    }
    cout << maxday;
    return 0;
}

//3.11
#include<iostream>
using namespace std;
int main(){
    int n,n1,n2,n3,p1,p2,p3,t1,t2,t3,total;
    cin>>n>>n1>>p1>>n2>>p2>>n3>>p3;
    t1=!(n%n1)?n/n1*p1:(n/n1+1)*p1;//还可以使用cmath中的ceil()函数，向上取整
    t2=!(n%n2)?n/n2*p2:(n/n2+1)*p2;
    t3=!(n%n3)?n/n3*p3:(n/n3+1)*p3;
    total=t1;
    if(t2<total) total=t2;
    if(t3<total) total=t3;
    cout<<total<<endl;
    return 0;
}

//3.12
法一：整个字符串
#include <iostream>
#include <string>
using namespace std;
int main() {
    string isbn;
    cin >> isbn;  // 输入一个完整的 ISBN 字符串
    // 提取数字部分和识别码部分
    int check = 0;
    for (int i = 0; i < 9; ++i) {
        check += (isbn[i] - '0') * (i + 1);  // 计算加权和
    }
    check %= 11;  // 计算模11
    // 获取识别码部分
    char givenCheck = isbn[10];
    // 判断识别码是否正确
    if ((check == 10 && givenCheck == 'X') || (check != 10 && givenCheck == check + '0')) {
        cout << "Right" << endl;
    } else {
        // 输出正确的 ISBN，注意处理识别码部分
        cout << isbn.substr(0, 9) << '-' << isbn.substr(9, 1) << (check == 10 ? 'X' : check + '0') << endl;
    }
    return 0;
}

法二：单个字符
#include<cstdio>
int main(){
    char a,b,c,d,e,f,h,g,i,j;
    int check;
    scanf("%c-%c%c%c-%c%c%c%c%c-%c",&a,&b,&c,&d,&e,&f,&g,&h,&i,&j);
    check=(a-'0')*1+(b-'0')*2+(c-'0')*3+(d-'0')*4+(e-'0')*5+(f-'0')*6+(g-'0')*7+(h-'0')*8+(i-'0')*9;
    check%=11;
    if(j=='X'&&check==10||check==j-'0'){
        printf("Right\n");
    }else{
        printf("%c-%c%c%c-%c%c%c%c%c-%c",a,b,c,d,e,f,g,h,i,check==10?'X':check+'0');
    }
    return 0;
}





