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

const ll oo=1e18;
const int mod=1e9+7;
const int N=1e6+5;

int di[]={-1,0,0,1,-1,-1,1,1};
int dj[]={0,-1,1,0,-1,1,-1,1};
/**/
int n;
v a;
set<ii>s;
/*main*/
void solution(){
    int id=0,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        a.push_back(x);
    }
    for(int i=0;i<n;i++){
        if(s.size()<2)s.insert({a[i],i});
        else{
            while(s.size()>1){
                auto t= ++s.begin();
                if(t->fi+s.begin()->fi<=a[i]||s.begin()->fi+a[i]<=s.rbegin()->fi){
                    s.erase({a[id],id});
                    id++;
                }
                else break;
            }
            s.insert({a[i],i});
            int len=s.size();
            if(s.size()>2)ans=max(ans,len);
        }
    }
    cout<<ans;
}
/**/
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    // freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
    int t=1;
    // cin>>t;
    while(t--){
        solution();
    }
    return 0;
}
/*THE END*/
