#include<bits/stdc++.h>
using namespace std; 
/*Start*/
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
/*Main*/
void init(){
    #define x first
    #define y second
}
bool cal_hull(ii a,ii b,ii c){
    init();
    int val=(c.x-b.x)*(b.y-a.y)
            -(c.y-b.y)*(b.x-a.x);
    if(val<0)return 1;
    return 0;
}
vector<ii> Convexhull(vector<ii> point){
    init();
    int n=point.size();
    vector<ii>hull;
    if(n<3)return hull;
    int finish=0,id=0;
    for(int i=1;i<n;i++){
        if(point[i].x<point[id].x)id=i;
    }
    finish=id;
    do{
        hull.push_back(point[id]);
        int d=(id+1)%n;
        for(int i=0;i<n;i++){
            if(cal_hull(point[id],point[i],point[d]))d=i;
        }
        id=d;
    }while(id!=finish);
    // for(int i=0;i<hull.size();i++)cout<<hull[i].x<<" "<<hull[i].y<<endl;
    return hull;

}
void solution(){
    int n;
    cin>>n;
    vector<ii> a(n);
    for(auto &x:a)cin>>x.fi>>x.se;
    a=Convexhull(a);
    if(a.size()==n)cout<<1<<endl;
    else cout<<0<<endl;
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
