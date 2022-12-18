#include <bits/stdc++.h>
using namespace std;
/*Start*/
/*
   ██          ██
   █▒█        █▒█
  █▒███    ███▒█
  █▒████████▒▒█
  █▒████▒▒█▒▒██
  ████▒▒▒▒▒████
   █▒▒▒▒▒▒▒████
  █▒▒▒▒▒▒▒▒████      █
 ██▒█▒▒▒▒▒█▒▒████  █▒█
 █▒█●█▒▒▒█●█▒▒███ █▒▒█
 █▒▒█▒▒▒▒▒█▒▒▒██ █▒▒█
  █▒▒▒=▲=▒▒▒▒███ ██▒█
  ██▒▒█♥█▒▒▒▒███  ██▒█
    ███▒▒▒▒████    █▒█
      ██████        ███
       █▒▒████      ██
       █▒▒▒▒▒████ _██
       █▒██▒██████▒█
       █▒███▒▒▒█████
     █▒████▒▒▒▒████
      █▒███▒██████
*/
#define int long long
#define ll long long
#define db double
#define x first
#define h second

typedef pair<int, int> ii;
typedef vector<int> v;

const ll oo = 1e13;
const int mod = 1e9 + 7;
const int N = 1e5 + 5;

int di[] = {-1, 0, 0, 1, -1, -1, 1, 1};
int dj[] = {0, -1, 1, 0, -1, 1, -1, 1};
/**/
int n, d;
ii dl[N];
int Tree[4 * N];
/*Main*/
void init()
{
    memset(Tree,0,sizeof(Tree));
    // dp.clear();
}
bool cmp(ii x, ii y)
{
    return x.x < y.x;
}
int search_left(int i)
{
    int id = 1;
    int l = 1, r = n;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (dl[m].x >= i)
        {
            id = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    return id;
}
int search_right(int i)
{
    int id = n;
    int l = 1, r = n;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (dl[m].x <= i)
        {
            id = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    return id;
}
void build(int node, int l, int r)
{
    if (l == r)
        Tree[node] = dl[l].h;
    else
    {
        build(2 * node, l, (l + r) / 2);
        build(2 * node + 1, (l + r) / 2 + 1, r);
        Tree[node] = max(Tree[2 * node], Tree[2 * node + 1]);
    }
}
int get(int node, int l, int r, int left, int right)
{
    if (l > right || r < left)
        return 0;
    if (l >= left && r <= right)
        return Tree[node];
    return max(get(2 * node, l, (l + r) / 2, left, right), get(2 * node + 1, (l + r) / 2 + 1, r, left, right));
}
void solution()
{
    int cnt = 0;
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
    {
        cin >> dl[i].x >> dl[i].h;
    }
    sort(dl + 1, dl + n + 1, cmp);
    build(1, 1, n);
    for (int i = 1; i <= n; i++)
    {
        int l = search_left(dl[i].x - d);
        int r = search_right(dl[i].x + d);
        int h1 = get(1, 1, n, l, i);
        int h2 = get(1, 1, n, i, r);
        if (h1 >= 2 * dl[i].h && h2 >= 2 * dl[i].h){
            // cout<<dl[i].x<<endl;
            cnt++;
        }
    }
    cout << cnt << endl;
}
//  __6___32___732
/**/
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    // cin>>t;
    while (t--)
    {
        init();
        solution();
    }
    return 0;
}
/*THE END*/
