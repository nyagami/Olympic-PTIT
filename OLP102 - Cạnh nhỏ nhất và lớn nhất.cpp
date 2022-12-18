#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using ull = unsigned long long;
using i128 = __int128_t;
using db = double;
using ii = pair<ll, ll>;

#define fi first
#define se second
#define in binary_search
#define vec vector
#define pb push_back
#define all(a) a.begin(), a.end()
#define umap unordered_map
#define For(i, a, b) for (ll i = (ll)a; i <= (ll)b; i++)
#define Ford(i, a, b) for (ll i = (ll)a; i >= (ll)b; i--)
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
istream &operator>>(istream &in, pair<T1, T2> &x)
{
    return in >> x.fi >> x.se;
}
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

ll _max(ll a, ll b, ll c) { return max(a, max(b, c)); }
ll _min(ll a, ll b, ll c) { return min(a, min(b, c)); }

umap<ll, ll> compress(vec<ll> a)
{
    sort(all(a));
    uniq(a);
    umap<ll, ll> ans;
    For(i, 0, a.size() - 1) ans[a[i]] = i + 1;
    return ans;
}

ll powermod(ll a, ll b, ll mod)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a % mod;
        b /= 2;
        a = a * a % mod;
    }
    return ans;
}

const ll mod = 1e9 + 7;
const int inf = 1e6;
const ll N = 2e5 + 5;

int di[] = {-1, 0, 0, 1, -1, -1, 1, 1};
int dj[] = {0, -1, 1, 0, -1, 1, -1, 1};

int n, m;
int f[N], h[N];
vec<ii> g[N];
int p[N][20];
struct note
{
    int maxC, minC;
    note()
    {
        maxC = -inf, minC = inf;
    }
} up[N][20];

int find(int node)
{
    return (f[node] == node ? node : f[node] = find(f[node]));
}
void dfs(int u)
{
    for (auto [v, c] : g[u])
    {
        if (h[v] == -1)
        {
            p[v][0] = u;
            h[v] = h[u] + 1;
            dfs(v);
            up[v][0].maxC = c;
            up[v][0].minC = c;
        }
    }
}

void Prepare()
{
    h[1] = 0;
    dfs(1);

    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 1; i <= n; i++)
            if (p[i][j - 1] != -1)
            {
                p[i][j] = p[p[i][j - 1]][j - 1];
                up[i][j].maxC = max(up[i][j - 1].maxC, up[p[i][j - 1]][j - 1].maxC);
                up[i][j].minC = min(up[i][j - 1].minC, up[p[i][j - 1]][j - 1].minC);
            }
}

note LCA(int u, int v)
{
    note res = note();
    if (h[u] > h[v])
        swap(u, v);
    for (int i = 19; i >= 0; i--)
        if (h[v] - (1 << i) >= h[u])
        {
            res.maxC = max(res.maxC, up[v][i].maxC);
            res.minC = min(res.minC, up[v][i].minC);
            v = p[v][i];
        }

    if (u == v)
        return res;

    for (int i = 19; i >= 0; i--)
        if (p[u][i] != p[v][i])
        {
            res.maxC = max(max(res.maxC, up[u][i].maxC), up[v][i].maxC);
            res.minC = min(min(res.minC, up[u][i].minC), up[v][i].minC);
            u = p[u][i], v = p[v][i];
        }
    if (u != v)
    {
        res.maxC = max(res.maxC, max(up[u][0].maxC, up[v][0].maxC));
        res.minC = min(res.minC, min(up[u][0].minC, up[v][0].minC));
    }
    return res;
}

void init()
{
    For(i, 1, n)
    {
        g[i].clear();
        f[i] = i;
        h[i] = -1;
        For(j, 1, 19){
            up[i][j] = note();
            p[i][j] = -1;
        }
    }
}

void solution()
{
    cin >> n;
    // cin >> n >> m;
    init();
    For(i, 1, n - 1){
        ll x, y, w;
        cin >> x >> y >> w;
        g[x].pb({y, w});
        g[y].pb({x, w});
    }
    Prepare();
    cin >> m;
    For(i, 1, m){
        ll x, y;
        cin >> x >> y;
        note ans = LCA(x, y);
        cout << ans.minC << " " << ans.maxC << endl;
    }
    // vec<tuple<int, int, int>> a;
    // For(i, 1, m)
    // {
    //     int type;
    //     cin >> type;
    //     if (type == 1)
    //     {
    //         int u, v;
    //         cin >> u >> v;
    //         int fu = find(u), fv = find(v);
    //         if (fu != fv)
    //         {
    //             f[fu] = fv;
    //             g[u].pb({v, i});
    //             g[v].pb({u, i});
    //         }
    //     }
    //     else
    //     {
    //         int u, v;
    //         cin >> u >> v;
    //         a.pb({u, v, i});
    //     }
    // }
    // Prepare();
    // for (auto [u, v, idx] : a)
    // {
    //     int fu = find(u), fv = find(v);
    //     if (fu != fv)
    //     {
    //         cout << -1 << endl;
    //         continue;
    //     }
    //     int ans = LCA(u, v).maxC;
    //     cout << ((ans < idx && ans > 0) ? ans : -1) << endl;
    // }
}

main()
{
    // FILEIN;
    // FILEOUT;
    FAST;
    int T = 1;
    // cin >> T;
    For(i, 1, T)
    {
        // cout << "TEST " << i << ":\n";
        db start = (db)(clock());
        solution();
        db end = (db)(clock());
        // cerr << "TEST " << i << ":" << (end - start) / CLOCKS_PER_SEC << "s" << endl;
    }
    return 0;
}
