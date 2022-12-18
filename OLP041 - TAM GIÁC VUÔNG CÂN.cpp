#include<bits/stdc++.h>
using namespace std; 
//S31[:v]
#define int long long 
#define fi first
#define se second
typedef pair <int,int> ii;
typedef vector<int> vi;
typedef vector<string> vs;
const int oo=INT_MAX;
const int mod=1e9+7;
const int N=1e5+5;
int di[]={-1,0,0,1};
int dj[]={0,-1,1,0};
//
int x,y,ans;
int getx(int l,int r){
    l=max(l,0ll);
    r=min(r,x);
    return r-l+1;
}
int gety(int l,int r){
    l=max(l,0ll);
    r=min(r,y);
    return r-l+1;
}
void solve(int i,int j){
    ans+=getx(i-j,i-j+y)*gety(i+j-x,i+j)-1;
    ans+=getx(i+j-y,i+j)*gety(-i+j,-i+j+x)-1;
}
//
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    // freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>x>>y;
        ans=0;
        for(int i=0;i<=x;i++){
            for(int j=0;j<=y;j++){
                solve(i,j);
            }
        }
        cout<<ans/2<<endl;
    }

    return 0;
}
//n
