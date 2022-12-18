#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int d[N];
void era(){
    memset(d,0,sizeof(d));
}
//so phan tu dung truoc no lon hon no max
int bit1(int x){
    int ans=0;
    for(;x<N;x+=x&-x)ans+=d[x];
    return ans;
}
void update1(int x){
    for(;x>0;x-=x&-x)d[x]++;
}
//
//so phan tu dung sau no nho hon no max
int bit2(int x){
    int ans=0;
    for(;x>0;x-=x&-x)ans+=d[x];
    return ans;
}
void update2(int x){
    for(;x<N;x+=x&-x)d[x]++;
}
//
int check(int a[],int n){
    era();
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=bit1(a[i]);
        update1(a[i]);
    }
    return ans;
}
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int ans=0;
    int n;
    cin>>n;
    int a[n+1];
    int d1[n+1];
    int d2[n+1];
    for(int i=1;i<=n;i++)cin>>a[i];
    //bai toan con voi phep bien doi thu 2
    ans=check(a,n);
    //
    //bai toan con thu 1
    era();
    for(int i=1;i<=n;i++){
        d1[i]=bit1(a[i]+1);
        update1(a[i]);
    }
    //
    //bai toan con thu 2
    era();
    for(int i=n;i>=1;i--){
        d2[i]=bit2(a[i]-1);
        update2(a[i]);
    }
   int maxd1=0,maxd2=0;
    for(int i=1;i<=n;i++){
        maxd1=max(maxd1,d1[i]);
        maxd2=max(maxd2,d2[i]);
    }
    vector<int>x;
    vector<int>y;
    for(int i=1;i<=n;i++){
        if(d1[i]==maxd1)x.push_back(i);
        if(d2[i]==maxd2)y.push_back(i);
    }
    era();
    for(int i=0;i<x.size();i++){
        for(int j=0;j<y.size();j++){
            int id1=x[i],id2=y[j];
            swap(a[id1],a[id2]);
            int res=check(a,n);
            ans=min(ans,res+1);
            swap(a[id1],a[id2]);
        }
    }
    cout<<ans;
    return 0;
}
