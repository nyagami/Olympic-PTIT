#include<bits/stdc++.h>
using namespace std;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
void sol() 
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>a(n,vector<int>(m));
    for(int i=0;i<n;i++) 
	{
        for(int j=0;j<m;j++) cin>>a[i][j];
    }
    vector<vector<int>>h(n,vector<int>(m,0));
    for(int i=0;i<n;i++) 
	{
        iota(h[i].begin(),h[i].end(),0);
        sort(h[i].begin(),h[i].end(),[&](int x,int y) 
		{
            return a[i][x]>a[i][y];
        });
    }
    vector<vector<int>>best(n,vector<int>(m,0));
    {
        vector<vector<int>>na=a;
        for(int i=0;i<n;i++) 
		{
            for(int j=0;j<m;j++) na[i][j]=a[i][h[0][j]];
        }
        sort(na.begin(),na.end(),greater<vector<int>>());
        best=na;
    }
    vector<vector<int>>na=a;
    for(int choose=1;choose<n;choose++) 
	{
        for(int i=0;i<n;i++) 
		{
            for(int j=0;j<m;j++) na[i][j]=a[i][h[choose][j]];
        }    
        sort(na.begin(),na.end(),greater<vector<int>>());
        bool ok=true;
        for(int i=0;ok&&i<n;i++) 
		{
            for(int j=0;ok&&j<m;j++) 
			{
                if(best[i][j]!=na[i][j]) 
				{
                    ok=false;
                    if(best[i][j]<na[i][j]) swap(best,na);
                }
            }
        }
    }
    int q;
    cin>>q;
    while(q--) 
	{
        int x,y;
        cin>>x>>y;
        x--; 
		y--;
        cout<<best[x][y]<<'\n';
    }
}
int main(int argc,char *argv[]) 
{
    ios_base::sync_with_stdio(0); 
	cin.tie(nullptr); 
	cout.tie(nullptr);
    sol();
    return 0;
}
