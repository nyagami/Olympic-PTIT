#include<bits/stdc++.h>
using namespace std;
int t,n;
string s;
int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--) 
	{
        cin>>s;
        n=s.size()-1;
        int cnt1=0,cnt2=0;
        long long res=0;
        string l="";
        string r="";
        for(int i=0;i<=n;i++) 
		{
            l+=s[i];
            r=s[n-i]+r;
            if(l==r) res+=pow(2,i+1);
        }
        cout<<res<<"\n";
    }
    return 0;
}
