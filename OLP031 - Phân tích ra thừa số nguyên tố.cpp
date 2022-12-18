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
vector<bool> a(1e7+5,1);
v e;
void era(){
    for(int i=2;i<=10000000;i++){
        if(a[i]){
            e.push_back(i);
            for(int j=i*i;j<=10000000;j+=i)a[j]=0;
        }
    }
}
//
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    era();
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<e.size();i++){
            if(e[i]*e[i]>n)break;
            if(a[e[i]]&&n%e[i]==0){
                int s=0;
                while(n%e[i]==0){
                    s++;
                    n/=e[i];
                }
                cout<<e[i]<<" "<<s<<endl;
            }
        }
        if(n>1)cout<<n<<" "<<1<<endl;
    }
    return 0;
}
//TheEnd
