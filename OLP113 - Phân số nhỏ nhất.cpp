#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<deque>
#include<algorithm>
#include<string>
#define ull unsigned long long
using namespace std;
ull ansa,ansb;
inline bool check(string& up,string su,string& tmp)
{
	string tmp2;
	int has=0;
	for(int i=0;i!=up.size();i++)
	{
		if(has<su.size()&&su[has]==up[i])
		{
			++has;
		}
		else
		{
			tmp2+=up[i];
		}
	}
	if(has<su.size()) return 0;
	sort(tmp.begin(),tmp.end());
	sort(tmp2.begin(),tmp2.end());
	return tmp==tmp2;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	string a,b;
	for(;n--;)
	{
		cin>>a>>b;
		ull _a=atoll(a.c_str());
		ull _b=atoll(b.c_str());
		ansa=_a,ansb=_b;
		for(int mask=0;mask!=(1<<b.size());mask++)
		{
			ull z=0;
			string tmp;
			for(int i=0;i!=b.size();i++)
			{
				if(mask&(1<<i)) z=z*10+b[i]-'0';
				else tmp+=b[i];
			}
			ull y=z*(static_cast<long double>(_a)/_b);
			if(!z||y*_b!=z*_a) continue;
			if(y<ansa&&check(a,to_string(y),tmp))
			{
				ansa=y,ansb=z;
			}
		}
		cout<<ansa<<" "<<ansb<<endl;
	}
}
