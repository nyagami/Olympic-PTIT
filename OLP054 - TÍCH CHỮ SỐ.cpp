#include<bits/stdc++.h>
using namespace std; 
//
#define int long long 
#define fi first
#define se second
typedef pair <int,int> ii;
typedef vector<int> v;
int di[]={-1,0,0,1};
int dj[]={0,-1,1,0};
//
int n;
//
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        if(n==1){
            cout<<1<<endl;
            continue;
        }
        v a;
        for(int i=9;i>=2;i--){
            while(n%i==0){
                a.push_back(i);
                n/=i;
            }
        }
        if(n==1){
            for(int i=a.size()-1;i>=0;i--)cout<<a[i];
            cout<<endl;
        }
        else cout<<-1<<endl;

    }
    return 0;
}
//
