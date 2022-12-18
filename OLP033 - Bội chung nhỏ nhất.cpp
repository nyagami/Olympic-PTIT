#include<bits/stdc++.h>
using namespace std; 
//S31[:v]
#define int long long 
#define fi first
#define se second
typedef pair <int,int> ii;
typedef vector<int> v;
int di[]={-1,0,0,1};
int dj[]={0,-1,1,0};
//
const int p=1e9+7;
vector<bool> a(1e6+5,1);
v e;
void era(){
    for(int i=2;i<=1000000;i++){
        if(a[i]){
            e.push_back(i);
            for(int j=i*i;j<=1000000;j+=i)a[j]=0;
        }
    }
}
int cnt(int n,int k){
    if(n<k)return 0;
    int d=n/k;
    d+=cnt(d,k);
    return d;
}
//
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    era();
    int t;
    cin>>t;
    while(t--){
        int m,n;
        cin>>m>>n;
        int ans=1;
        for(int i=0;i<e.size();i++){
            if(a[i]>n)break;
            int d1=cnt(n,e[i]);
            int d2=cnt(m-1,e[i]);
            ans=ans*(2*(d1-d2)+1)%p;
        }
        cout<<ans<<endl;
    }
    return 0;
}
//TheEnd
