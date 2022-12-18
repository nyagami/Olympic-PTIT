#include<bits/stdc++.h>
using namespace std; 
//S31[:v]
#define int long long 
#define fi first
#define se second
typedef pair <int,int> ii;
typedef vector<int> v;
typedef vector<vector<int>> vv;
int di[]={-1,0,0,1};
int dj[]={0,-1,1,0};
//
const int N=1e6+5;
int f[N];
vector<bool> a(1e6+5,1);
v e;
void era(){
    for(int i=2;i<=N;i++){
        if(a[i]){
            e.push_back(i);
            for(int j=i*i;j<=N;j+=i)a[j]=0;
        }
    }
}
int pow(int n,int k,int p){
    if(k==0)return 1;
    int d=pow(n,k/2,p);
    if(k%2==0)return d*d%p;
    return d*d*n%p;
}
int get(int p,int n){
    if(n<p)return 0;
    return n/p + get(p,n/p);
}
void fibo(int n,int mod){
    f[0]=1%mod;  f[1]=2%mod;
    for(int i=2;i<=n;i++)f[i]=(f[i-1]+f[i-2])%mod;
}
//
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    era();
    int t;
    cin>>t;
    while(t--){
        int n,mod;
        cin>>n>>mod;
        fibo(n,mod);
        int res;
        if(n%2==1)res=f[n];
        else{
            res=f[n];
            int c=1;
            for(int i=0;i<e.size();i++){
                int k=get(e[i],n) - 2*get(e[i],n/2);
                assert(k>=0);
                c=c*pow(e[i],k,mod)%mod;
            }
            res=(res+c)%mod;
            res=(res-(n/2+1)%mod+mod)%mod;
        }
        cout<<res<<endl;
    }
    return 0;
}
//TheEnd
