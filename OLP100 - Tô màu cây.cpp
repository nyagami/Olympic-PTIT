
/* Created by Tran Duc Huy */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define ll long long
#define ull unsigned long long
#define db double
#define fi first
#define se second
#define in binary_search
#define vec vector
#define pb push_back
#define Pop pop_back
#define rv greater
#define umap unordered_map
#define all(a) a.begin(), a.end()
#define reset(a, val) memset(a, val, sizeof(a));
#define For(i, a, b) for (ll i = (ll)a; i <= (ll)b; i++)
#define Ford(i, a, b) for (ll i = (ll)a; i >= (ll)b; i--)
#define lb lower_bound
#define ub upper_bound
#define uniq(a) a.resize(unique(all(a)) - a.begin())
#define FILEIN freopen("input.txt", "r", stdin)
#define FILEOUT freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

template <typename T1, typename T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &x)
{
    return out << x.fi << ',' << x.se;
}
template <typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &x) { return in >> x.fi >> x.se; }
template <typename T>
istream &operator>>(istream &in, vector<T> &a)
{
    for (auto &x : a)
        in >> x;
    return in;
};
template <typename T>
ostream &operator<<(ostream &out, vector<T> &a)
{
    for (auto &x : a)
        out << x << ' ';
    return out;
};
template <typename T>
istream &operator>>(istream &in, deque<T> &a)
{
    for (auto &x : a)
        in >> x;
    return in;
};
template <typename T>
ostream &operator<<(ostream &out, deque<T> &a)
{
    for (auto &x : a)
        out << x << ' ';
    return out;
};
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
template <class T>
using maxpq = priority_queue<T, vector<T>>;
template <class A, class B>
using pq = priority_queue<A, vector<A>, B>;

typedef pair<int, int> ii;
typedef pair<int, ii> i_ii;
typedef pair<ii, int> ii_i;
typedef pair<ii, ii> ii_ii;
typedef pair<int, char> ic;
typedef pair<char, int> ci;
typedef pair<int, string> is;
typedef pair<string, int> si;
typedef pair<db, db> dd;
typedef vector<ii> vii;
typedef vector<int> v;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<v> vv;

const int mod = 1e9 + 7;

int _max(int a, int b, int c) { return max(a, max(b, c)); }
int _min(int a, int b, int c) { return min(a, min(b, c)); }

template <typename T>
T random(const T &a, const T &b)
{
    T m = b - a + 1;
    return a + rand() % m;
}
ll to_int(string s)
{
    ll ans = 0;
    for (auto x : s)
        ans = ans * 10 + (x - '0');
    return ans;
}
v compress(v a)
{
    v c = a;
    sort(all(c));
    uniq(c);
    for (int i = 0; i < a.size(); i++)
    {
        a[i] = lb(all(c), a[i]) - c.begin();
    }
    return a;
}
ll power(ll a, int b)
{
    int r = 1;
    while (b)
    {
        if (b & 1)
        {
            // r *= a;
            r = (r * a) % mod;
        }
        b >>= 1;
        // a *= a;
        a = (a * a) % mod;
    }
    return r;
}
void read(int a[], int n)
{
    For(i, 1, n) cin >> a[i];
}
void print(int a[], int n)
{
    For(i, 1, n) cout << a[i] << " ";
    cout << endl;
}
const ll oo = (ll)1 << 60;
const db PI = 3.14159265358979323846;
const int N = 2e5 + 5;

int di[] = {-1, 0, 0, 1, -1, -1, 1, 1};
int dj[] = {0, -1, 1, 0, -1, 1, -1, 1};
/**/
ll n;
v g[N];
ll dp[N][25];

void dfs(ll u, ll pre){
    For(i, 1, 20) dp[u][i] = i;
    for(auto x: g[u]){
        if(x == pre) continue;
        dfs(x, u);
        For(i, 1, 20){
            ll value = oo;
            For(j, 1, 20){
                if(i != j)
                    value = min(value, dp[x][j]);
            }
            dp[u][i] += value;
        }
    }
}
/*Main*/
void init()
{
    For(i, 1, n){
        g[i].clear();
        For(j, 1, 20) dp[i][j] = 0;
    }
}

void solution()
{
    cin >> n;
    init();
    For(i, 1, n){
        ll x;
        cin >> x;
        g[x].pb(i);
    }
    dfs(1, 0);
    cout << *min_element(dp[1] + 1, dp[1] + 21) << endl;
}
/**/
main()
{
    FAST;
    ll T = 1;
    cin >> T;
    For(i, 1, T)
    {
        // cout << "TEST " << i << ":\n";
        solution();
    }
    return 0;
}
