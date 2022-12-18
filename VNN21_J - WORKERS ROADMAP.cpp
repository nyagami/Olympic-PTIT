#include<iostream>
using namespace std;
const long long MAX_DAY=1e16;
int n;
long long a[110],b[110];
long long m;
int main()
{
    cin>>n>>m;
    for(int i(0);i<n;i++) cin>>a[i]>>b[i];
    long long l=0,r=1;
    while(1)
	{
        long long sum=0;
        for(int i(0);i<n;i++) sum=sum+(r-r/(b[i]+1))*a[i];
        if(sum>=m) break;
        else r<<=1;
    }
    long long res=0;
    r=r+1;
    while(l<r)
    {
        long long sum=0;
        long long mid=(l+r)>>1;
        for(int i(0);i<n;i++)
        {
            long long d=mid/(b[i]+1);
            sum=sum+(mid-d)*a[i];
        }
        if(sum>=m)
        {
            res=mid;
            r=mid;
        }
        else l=mid+1;
    }
    cout<<res;
}
