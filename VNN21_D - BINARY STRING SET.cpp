#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        int n;
        cin>>s;
        n=s.length();
        s='1'+s+'1';
        char pre='1';
        int cnt=0;
        for(int i(1);i<=n;i++)
		{
            if(s[i]=='1')
			{
                if(pre=='1')
				{
                    if(s[i+1]=='0')
                    {
                        cnt+=2;
                        i++;
                    }
                    continue;
                }
                else
				{
                    cnt+=1;
                    pre='1';
                }
            }
            else
			{
                cnt+=1;
                pre='0';
            }
        }
        cout<<n-cnt<<endl;
    }
}
