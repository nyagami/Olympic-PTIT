#include<bits/stdc++.h>
using namespace std; 
/*Start*/
#define int long long 
#define ll long long
#define db double
#define fi first
#define se second

typedef pair <int,int> ii;
typedef pair <db,db> dd;

typedef vector<int> v;

const ll oo=1e13;
const int mod=1e9+7;
const int N=1e6+5;

int di[]={-1,0,0,1,-1,-1,1,1};
int dj[]={0,-1,1,0,-1,1,-1,1};
/**/
int n;
int x[N],y[N];
/*Main*/
void init(){
    // a.clear();
}
void solution(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>x[i]>>y[i];
    vector<ii> tmp;
    int ans=0,k=1;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            tmp.push_back({x[i]+x[j],y[i]+y[j]});
        }
    }
    sort(tmp.begin(),tmp.end());
    for(int i=0;i<tmp.size()-1;i++){
        if(tmp[i]==tmp[i+1])k++;
        else {
            ans+=k*(k-1)/2;
            k=1;
        }
    }
    ans+=k*(k-1)/2;
    cout<<ans<<endl;
    // for(auto x:tmp)cout<<x.fi<<","<<x.se<<" ";
    // cout<<endl;
}
/**/
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    // freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
    int t=1;
    cin>>t;
    while(t--){
        init();
        solution();
    }
    return 0;
}
/*THE END*/
