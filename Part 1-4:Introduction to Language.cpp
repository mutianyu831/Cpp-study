//4.1
#include<iostream>
using namespace std;
int main(){
  int L,i;
  cin>>L;
  for(i=1;i<=L;i++){
    cout<<"Today ,I ate "<< i << "apple";
    if(i!=0&&i!=1) cout << "s";
    cout << "." << endl;
  }
  return 0;
}

///4.2
#include<iostream>
using namespace std;
int main(){
    int n,tmp,minnum=100000000;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>tmp;
        if(tmp<minnum)
            minnum=tmp;
    }
    cout<<minnum<<endl;
}

//4.3
#include<cstdio>
using namespace std;
int main(){
    int n,k,acount=0,bcount=0;
    double asum=0.0,bsum=0.0;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        if(i%k==0){
            asum+=i;
            acount++;
            
        }else{
            bsum+=i;
            bcount++;
        }
    }
    printf("%.1f %.1f",asum/acount,bsum/bcount);
    return 0;
}

//4.4
#include<iostream>
using namespace std;
int main(){
    int a,day=1;
    cin>>a;
    while(a>1){
        day++;
        a/=2;
    }
    cout<<day;
}

//4.5
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
  int ans,guess;
  srand(time(0));
  ans=rand()%100+1;
  do{
    cin>>guess;
    if(guess<ans)
      cout<<"Too small"<<endl;
    if(guess>ans)
      cout<<"Too large"<<endl;
  }while(ans!=guess);
  cout<<"You are right!!"<<endl;
  return 0;
}

//4.6
#include<iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int j = n,count=0;
    for (int i = 1; i <= n * (n + 1) / 2; i++) {
        if (i <= 9)  cout << "0" << i;
        else    cout << i;
        count++;
        if (count==j) {
            cout << endl;
            count = 0;
            j--;
        }
    }
    return 0;
}

//4.7 涉及高精度，暂时无法做

//4.8
#include<iostream>
using namespace std;
int main(){
    int x,n,ans=0;
    cin>>n>>x;
    for(int i=1;i<=n;i++){
        int temp=i,num;
        while(temp!=0){
            num=temp%10;
            if(num==x)
                ans++;
            temp/=10;
        }
    }
    cout<<ans;
    return 0;
}

///4.9
#include<iostream>
using namespace std;
int main(){
    int k,ans=0;
    cin>>k;
    for(double sn=0;sn<=k;ans++,sn+=1.0/ans);
    cout<<ans;
    return 0;
}

//4.10
#include<iostream>
using namespace std;
int main(){
    int k,coin=0,day=0;
    cin>>k;
    for(int i=1;;i++)
    for(int j=1;j<=i;j++){
        coin+=i;
        day++;
        if(day==k){
            cout<<coin<<endl;
            
            return 0;
        }
    }
    return 0;
}

//4.11
法一
#include<iostream>
using namespace std;
int main(){
    int s=0,n;
    cin>>n;
    for(int i=1;i<=n;i++){
        s+=i;
    }
    cout<<s;
    return 0;
}
法二
#include<iostream>
using namespace std;
int main(){
    int s=0,n,i=0;
    cin>>n;
    while(n--){
        s+= ++i;
    }
    cout<<s;
    return 0;
}

//4.12
#include<iostream>
using namespace std;
int main(){
  int n;
  double s=0;
  cin>>n;
  for(double i=0.1;i+0.01<n;i+=0.1){
    s+=1;
  }
  cout<<s;
  return 0;
}

//4.13
#include<iostream>
using namespace std;
int main(){
    int l,load=0,ans=0;
    cin>>l;
    for(int i=2;;i++){
        int is_prime=1;
        for(int j=2;j*j<=i;j++){
            if(i%j==0){
                is_prime = 0;
                break;
            }
        }
        if(!is_prime)  continue;
        if(i+load>l)   break;
        cout<<i<<endl;
        ans++;
        load+=i;
    }
    cout<<ans;
    return 0;
}

//4.14
csdn晚雾也有归处

