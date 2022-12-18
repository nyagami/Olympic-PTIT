#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> II;
const int N=1000000;
int n;
int a[16][16];
int F[N][16],dp[N][16];
II d[N];
int u,v,k;
void solve(){
    int last=(1<<n)-1;
    for(int i=1;i<=last;i++){
        for(int j=0;j<=n;j++){
            F[i][j]=INT_MAX;
            dp[i][j]=0;
        }
    }
    int l=1,r=0;
    d[++r]=II (0,0);
    dp[0][0]=1;
    F[0][0]=0;

    while(l<=r){
        II t=d[l++];
        u=t.first;
        k=t.second;
        for(int i=1;i<=n;i++){
            if((u&(1<<(i-1)))==0){
                v=u^(1<<(i-1));
                F[v][i]=min(F[v][i],F[u][k]+a[k][i]);
                if(dp[v][i]==0){
                    dp[v][i]=1;
                    d[++r]=II (v,i);
                }
            }
        }
    }
    int ans=INT_MAX;
    for(int i=1;i<=n;i++){
        ans=min(ans,F[last][i]);
    }
    cout<<ans<<endl;
}
main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)cin>>a[i][j];
        }
        solve();
    }
}
