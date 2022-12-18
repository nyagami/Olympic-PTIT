#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define llu unsigned long long
#define pii pair<int, int>
#define fi first
#define sc second
const int MAX = 105;
const int dx[4]={0,0,-1,1};
const int dy[4]={-1,1,0,0};
char raw[MAX][MAX];
int allow[MAX][MAX];
int n,m,vis[MAX][MAX][4];
void preprocess()
{
	memset(allow,0,sizeof(allow));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(raw[i][j]=='^')
			{
				for(int k=i-1;k>=0&&raw[k][j]=='.';k--) allow[k][j]|=(1<<0);
				for(int k=j+1;k<m&&raw[i][k]=='.';k++) allow[i][k]|=(1<<1);
				for(int k=i+1;k<n&&raw[k][j]=='.';k++) allow[k][j]|=(1<<2);
				for(int k=j-1;k>=0&&raw[i][k]=='.';k--) allow[i][k]|=(1<<3);
			}
			else if(raw[i][j]=='>')
			{
				for(int k=i-1;k>=0&&raw[k][j]=='.';k--) allow[k][j]|=(1<<3);
				for(int k=j+1;k<m&&raw[i][k]=='.';k++) allow[i][k]|=(1<<0);
				for(int k=i+1;k<n&&raw[k][j]=='.';k++) allow[k][j]|=(1<<1);
				for(int k=j-1;k>=0&&raw[i][k]=='.';k--) allow[i][k]|=(1<<2);
			}
			else if(raw[i][j]=='v')
			{
				for(int k=i-1;k>=0&&raw[k][j]=='.';k--) allow[k][j]|=(1<<2);
				for(int k=j+1;k<m&&raw[i][k]=='.';k++) allow[i][k]|=(1<<3);
				for(int k=i+1;k<n&&raw[k][j]=='.';k++) allow[k][j]|=(1<<0);
				for(int k=j-1;k>=0&&raw[i][k]=='.';k--) allow[i][k]|=(1<<1);
			}
			else if(raw[i][j]=='<')
			{
				for(int k=i-1;k>=0&&raw[k][j]=='.';k--) allow[k][j]|=(1<<1);
				for(int k=j+1;k<m&&raw[i][k]=='.';k++) allow[i][k]|=(1<<2);
				for(int k=i+1;k<n&&raw[k][j]=='.';k++) allow[k][j]|=(1<<3);
				for(int k=j-1;k>=0&&raw[i][k]=='.';k--) allow[i][k]|=(1<<0);
			}
		}
	}
}
inline bool valid(int y,int x)
{
	if(y>=0&&y<n&&x>=0&&x<m)
	{
		return raw[y][x]=='.';
	}
	return false;
}
int sx,sy,gx,gy;
int main()
{
	int t;
	scanf("%d",&t);
	for(int tc=1;tc<=t;tc++)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
		{
			scanf("%s",raw[i]);
			for(int j=0;j<m;j++)
			{
				if(raw[i][j]=='S')
				{
					sy=i,sx=j;
					raw[i][j]='.';
				}
				else if(raw[i][j]=='G')
				{
					gy=i,gx=j;
					raw[i][j]='.';
				}
			}
		}
		preprocess();
		memset(vis,0,sizeof(vis));
		queue<pair<int, int>>bfs;
		queue<int> dist;
		vis[sy][sx][0]=1;
		bfs.push(pii(sy,sx));
		dist.push(0);
		bool ans=false;
		while(!bfs.empty())
		{
			int y=bfs.front().fi,x=bfs.front().sc,d=dist.front();
			if(y==gy&&x==gx)
			{
				printf("%d\n",d);
				ans=true;
				break;
			}
			bfs.pop(),dist.pop();
			for(int i=0;i<4;i++)
			{
				int cy=y+dy[i],cx=x+dx[i];
				if(!valid(cy,cx)) continue;
				if((allow[cy][cx]&(1<<((d+1)%4)))>0) continue;
				if(vis[cy][cx][(d+1)%4]) continue;
				vis[cy][cx][(d+1)%4]=1;
				bfs.push(pii(cy,cx));
				dist.push(d+1);
			}
		}
		if(ans==false)
		{
			printf("impossible\n");
		}
	}
}
