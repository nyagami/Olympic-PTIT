#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b,c,d,e,x,y;
    int ans=0;
    cin>>a>>b>>c>>d>>e;
    int arr[a+1][b+1];
    int s[a+1][b+1];
    for(int i=0;i<=a;i++){
        for(int j=0;j<=b;j++){
            arr[i][j]=0;
            s[i][j]=0;
        }
    }
    for(int i=0;i<c;i++){
        cin>>x>>y;
        arr[x][y]=1;
    }
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            s[i][j]=arr[i][j];
            if(j>1)s[i][j]+=s[i][j-1];
            arr[i][j]=1;
        }
        if(i>1)for(int j=1;j<=b;j++){
            s[i][j]+=s[i-1][j];
        }
    }
    
    for(int i=2;i<=a;i++){
        for(int j=2;j<=b;j++){
            int t=min(arr[i-1][j],arr[i][j-1]);
            int k=min(arr[i-1][j-1],t)+1;
            int sum=s[i][j]-s[i-k][j]-s[i][j-k]+s[i-k][j-k];
            if(sum<=e){
                arr[i][j]=k;
                if(k%d==0)ans=max(ans,k);
            }
            else arr[i][j]=k-1;
        }
    }
    cout<<ans;
    return 0;
}
