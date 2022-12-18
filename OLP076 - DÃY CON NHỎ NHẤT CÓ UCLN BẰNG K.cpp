#include<bits/stdc++.h>
using namespace std; 
/*S31*/
#define int long long 
#define ll long long
#define db double
#define fi first
#define se second

typedef pair <int,int> ii;
typedef vector<int> v;

const ll oo=1e15;
const int mod=1e9+7;
const int N=1e5+5;

int di[]={-1,0,0,1,-1,-1,1,1};
int dj[]={0,-1,1,0,-1,1,-1,1};
/**/
int n,k,ans;
int a[N];
vector <ii> List;
void reset(){
    ans=oo;
    List.clear();
}
void solve(int l,int r){
    int len=r-l+1;
    if(len>1000)len=10;
    for(int i=l;i<l+len;i++){
        int d=a[i];
        for(int j=i+1;j<=r;j++){
            d=__gcd(d,a[j]);
            if(d==k){
                ans=min(ans,j-i+1);
                break;
            }
        }
    }
}
/*main*/
void solution(){
    int left,right,ok=0;
    left=right=-1;
    cin>>n>>k;
    reset();
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==k)ans=1;
        else if(a[i]%k==0){
            if(left==-1)left=right=i;
            else right=i;
        }
        else{
            if(right!=-1){
                List.push_back({left,right});
                left=right=-1;
            }
        }
    }
    if(right!=-1)List.push_back({left,right});
    for(auto x:List){
        solve(x.fi,x.se);
    }
    if(ans==oo)cout<<-1<<endl;
    else cout<<ans<<endl;
}
/**/
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    // freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
    int t=1;
    cin>>t;
    while(t--){
        solution();
    }
    return 0;
}
/*THE END*/
