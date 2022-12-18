#include<bits/stdc++.h>
using namespace std; 
//S31[:v]
#define int long long 
#define fi first
#define se second
typedef pair <int,int> ii;
typedef vector<int> v;
int di[]={-1,0,0,1,-1,-1,1,1};
int dj[]={0,-1,1,0,-1,1,-1,1};
//
bool check(string s){
    stack <int> st;
    for(int i=0;i<s.size();i++){
        if(st.empty()||s[i]=='('||s[i]=='['||s[i]=='{')st.push(i);
        else if(s[i]==')'){
            int k=st.top();
            if(st.empty()||s[k]!='(')return 0;
            else st.pop();
        }
        else if(s[i]==']'){
            int k=st.top();
            if(st.empty()||s[k]!='[')return 0;
            else st.pop();
        }
        else if(s[i]=='}'){
            int k=st.top();
            if(st.empty()||s[k]!='{')return 0;
            else st.pop();
        }
    }
    if(!st.empty())return 0;
    return 1;
}
// 
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        if(check(s))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
//TheEnd
