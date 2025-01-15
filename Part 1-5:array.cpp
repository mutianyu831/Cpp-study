//5.1
#include<iostream>
using namespace std;
int main(){
    int a[110],n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=i-1;j>=0;j--){
            if(a[j]<a[i]){
                cnt++;
            }
            
        }
        cout<<cnt<<' ';
    }
    return 0;
}

//5.2
#include<iostream>
using namespace std;
int main(){
    long long arr[105];
    int count=0;
    for(int i=0;;i++){
        cin>>arr[i];
        count++;
        if(arr[i]==0)  break;
    }
    
    for(int i=count-2;i>=0;i--){
        cout<<arr[i]<<' ';
    }
}

//5.3
#include<iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int y = n;
    int arr[105], i = 0;
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
            arr[i++] = n;
        }
        else {
            n = n * 3 + 1;
            arr[i++] = n;
        }
    }
    for (int j = i - 1 ; j >= 0; j--) {
        cout << arr[j]<<' ';
    }
    cout << y;
    return 0;
}

//5.4校门外的数（模拟）

#include<iostream>
using namespace std;
int main(){
    int l,m,tree[10010]={0},a,b,s=0;
    cin>>l>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        for(int j=a;j<=b;j++){
            tree[j]=1;
        }
    }
    
    for(int i=0;i<=l;i++){
        if(tree[i]==0)  s++;
    }
    cout<<s<<endl;
    return 0;
}

//5.5
#include<iostream>
#include<cmath>
#define MAXN 1024
using namespace std;
int main(){
    int n,a[3][MAXN],ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[0][i]>>a[1][i]>>a[2][i];
    }
    for(int i=1;i<=n-1;i++){
        for(int j=i+1;j<=n;j++){
            if(abs(a[0][i]-a[0][j])<=5
            && abs(a[1][i]-a[1][j])<=5
            && abs(a[2][i]-a[2][j])<=5
            && abs(a[0][i]+a[1][i]+a[2][i]-a[0][j]-a[1][j]-a[2][j])<=10
            )   ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}

//5.6使用前缀和，暂时不需要做

//5.7






