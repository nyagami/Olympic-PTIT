#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int arr[20];
bool check[600]={false};
bool cnt(int res[],int id,int sum,int m,int key)
{
    if(id==m)
	{
        if(sum==key) return true;
        return false;
    }
    if(sum+res[id]<=key)
	{
        if(cnt(res,id+1,sum+res[id],m,key)) return true;
    }
    if(cnt(res,id+1,sum,m,key)) return true;
    return false;
}
int main()
{
    int n;
    cin>>n;
    for(int i(0);i<n;i++)
	{
        cin>>arr[i];
    }
    int ans=0;
    for(ll k(0);k<(1<<(n+1));k++)
	{
        int m=0;
        int res[20];
        int sum=0;
        for(int i(0);i<n;i++)
        if((k>>i)&1)
		{
            res[++m]=arr[i];
            sum+=arr[i];
        }
        if(sum&1) continue;
        if(cnt(res,0,0,m,sum/2)&&!check[sum/2])
        {
            ans++;
            check[sum/2]=true;
        };
    }
    cout<<ans-1<<endl;
    for(int i(1);i<=540;i++)
    {
        if(check[i]) cout<<i<<" ";
    }
}
