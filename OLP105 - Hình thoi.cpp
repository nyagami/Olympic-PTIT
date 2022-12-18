#include<bits/stdc++.h>
using namespace std; 
/*Start*/
/*
   ██          ██
   █▒█        █▒█
  █▒███    ███▒█
  █▒████████▒▒█
  █▒████▒▒█▒▒██
  ████▒▒▒▒▒████
   █▒▒▒▒▒▒▒████
  █▒▒▒▒▒▒▒▒████      █
 ██▒█▒▒▒▒▒█▒▒████  █▒█
 █▒█●█▒▒▒█●█▒▒███ █▒▒█
 █▒▒█▒▒▒▒▒█▒▒▒██ █▒▒█
  █▒▒▒=▲=▒▒▒▒███ ██▒█
  ██▒▒█♥█▒▒▒▒███  ██▒█
    ███▒▒▒▒████    █▒█
      ██████        ███
       █▒▒████      ██
       █▒▒▒▒▒████ _██
       █▒██▒██████▒█
       █▒███▒▒▒█████
     █▒████▒▒▒▒████
      █▒███▒██████
*/
#define int long long 
#define ll long long
#define db double
#define fi first 
#define se second

typedef pair <int,int> ii;
typedef vector<int> v;

const ll oo=1e13;
const int mod=1e9+7;
const int N=1e6+5;

int di[]={-1,0,0,1,-1,-1,1,1};
int dj[]={0,-1,1,0,-1,1,-1,1};
/**/
int n;
ii a[N];
map<ii,vector<ii>>List;
/*Main*/
bool check(ii x1,ii x2){
    return x1.fi*x2.fi+x1.se*x2.se==0;
}
void init(){}
void solution(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].fi>>a[i].se;
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            ii id={a[i].fi+a[j].fi,a[i].se+a[j].se};
            List[id].push_back({a[i].fi-a[j].fi,a[i].se-a[j].se});
        }
    }
    int cnt=0;
    for(auto vec:List){
        for(int i=0;i<vec.se.size();i++){
            for(int j=i+1;j<vec.se.size();j++){
                if(check(vec.se[i],vec.se[j]))cnt++;
            }
        }
    }
    cout<<cnt<<endl;


}
/**/
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    // freopen("input.txt", "r", stdin);
	  // freopen("output.txt", "w", stdout);
    int t=1;
    // cin>>t;
    while(t--){
        init();
        solution();
    }
    return 0;
}
/*THE END*/
