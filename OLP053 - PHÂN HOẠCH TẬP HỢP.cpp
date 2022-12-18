#include<bits/stdc++.h>
using namespace std; 
//
#define int long long 
#define fi first
#define se second
typedef pair <int,int> ii;
typedef vector<int> v;
int di[]={-1,0,0,1};
int dj[]={0,-1,1,0};
//
int n,sum;
int a[20];
int solve(int x){
    int ans=0;
    for(int i=1;i<=n;i++){
        if(x>>(i-1)&1)ans+=a[i];
    }
    return ans;
}
void solution(){
    int last=(1<<n)-1;
    int cnt=0; int d=sum/3;
    for(int i=1;i<=last;i++){
        int res=solve(i);
        if(res!=d)continue;
        for(int j=1;j<i;j++){
            if((i&j)==0){
                res=solve(j);
                if(res==d)cnt++;
            }
        }
    }
    cout<<cnt*2<<endl;
}
//
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        sum=0;
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        if(sum%3!=0)cout<<0<<endl;
        else {
            solution();
        }
    }
    return 0;
}
