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
        int n,k;
        cin>>n>>k;
        int ans=LONG_LONG_MAX;
        for(int i=0;i<e.size();i++){
            if(e[i]*e[i]>k)break;
            if(a[e[i]]&&k%e[i]==0){
                int s=0;
                while(k%e[i]==0){
                    s++;
                    k/=e[i];
                }
                ans=min(ans,cnt(n,e[i])/s);
            }
        }
        if(k>1)ans=min(ans,cnt(n,k)/1);
        cout<<ans<<endl;
    }
    return 0;
}
//TheEnd
