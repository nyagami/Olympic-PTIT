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
using db = double;

#define fi first
#define se second
#define in binary_search
#define vec vector
#define pb push_back
#define all(a) a.begin(), a.end()
#define For(i, a, b) for (ll i = (ll)a; i <= (ll)b; i++)
#define Ford(i, a, b) for (ll i = (ll)a; i >= (ll)b; i--)
#define uniq(a) a.resize(unique(all(a)) - a.begin())
#define FILEIN freopen("input.txt", "r", stdin)
#define FILEOUT freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define umap map

typedef pair<ll, ll> ii;

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
const ll inf = (ll)1 << 60;
const ll N = 1e5 + 5;
const ll maxn = 1e6 + 5;

int di[] = {-1, 0, 0, 1, -1, -1, 1, 1};
int dj[] = {0, -1, 1, 0, -1, 1, -1, 1};

ll n;
vec<ll> g[N], prime[N];
ll s[N], c[N], pref[N];
umap<ll, ll> mx[N], mx2[N], line[N], triple[N];
ll e[maxn];
ll ans = -inf;

void era()
{
    For(i, 1, maxn - 1) e[i] = i;
    for (ll i = 2; i * i < maxn; i++)
    {
        if (e[i] == i)
        {
            for (ll j = i * i; j < maxn; j += i)
                e[j] = i;
        }
    }
}

vec<ll> convert(ll x)
{
    vec<ll> p;
    while (x > 1)
    {
        p.pb(e[x]);
        x /= e[x];
    }
    sort(all(p));
    uniq(p);
    return p;
}

void dfs_max(ll node, ll pre)
{
    pref[node] = pref[pre] + s[node];
    for (auto it : prime[node])
    {
        mx[node][it] = pref[node];
        mx2[node][it] = -inf;
        line[node][it] = -inf;
    }
    for (auto x : g[node])
    {
        if (x == pre)
            continue;
        dfs_max(x, node);
        for (auto it : prime[node])
        {
            if (mx[x].count(it))
            {
                mx[node][it] = max(mx[node][it], mx[x][it]);
                mx2[node][it] = max(mx2[node][it], mx[x][it]);
            }
        }
    }
    for (auto it : prime[node])
    {
        if (mx2[node][it] != -inf)
            line[node][it] = max(line[node][it], mx2[node][it] - pref[pre]);
    }
}

void dfs_triple(ll node, ll pre)
{
    for (auto it : prime[node])
    {
        triple[node][it] = -inf;
    }
    umap<ll, vec<ii>> ls_sum, ls_max;
    // cout << node << endl;
    for (auto x : g[node])
    {
        if (x == pre)
            continue;
        dfs_triple(x, node);
        for (auto it : prime[node])
        {
            if (triple[x].count(it) && triple[x][it] != -inf)
            {
                triple[node][it] = max(triple[node][it], triple[x][it] + s[node] * 2);
                triple[node][it] = max(triple[node][it], line[x][it] * 2 + s[x] + s[node] * 2);
                ans = max(ans, triple[node][it]);
                ls_sum[it].pb({max(triple[x][it], line[x][it] * 2 + s[x]), x});
            }
            if (mx[x].count(it) && mx[x][it] != -inf)
            {
                ls_max[it].pb({mx[x][it], x});
            }
        }
    }
    for (auto it : prime[node])
    {
        vec<ii> Max = ls_max[it], Sum = ls_sum[it];
        sort(all(Max));
        sort(all(Sum));
        ll sz_max = Max.size(), sz_sum = Sum.size();
        if (Max.size() >= 3)
        {
            ll x = Max[sz_max - 1].fi - pref[pre], y = Max[sz_max - 2].fi - pref[pre], z = Max[sz_max - 3].fi - pref[pre];
            ans = max(ans, x * 2 + y * 2 + z * 2 - s[node] * 3);
        }
        if (Max.size() >= 2)
        {
            ll l = Max[sz_max - 1].fi - pref[pre], r = Max[sz_max - 2].fi - pref[pre];
            ll value = l * 2 + r * 2 - s[node];
            triple[node][it] = max(triple[node][it], value);
            ans = max(ans, value);
        }
        if (sz_max && sz_sum)
        {
            if (Max.back().se != Sum.back().se)
            {
                ll value = (Max.back().fi - pref[node]) * 2 + s[node] * 2 + Sum.back().fi;
                ans = max(ans, value);
            }
            else
            {
                if (sz_max >= 2 && sz_sum >= 2)
                {
                    ll l = (Max[sz_max - 1].fi - pref[pre]) * 2 + Sum[sz_sum - 2].fi;
                    ll r = (Max[sz_max - 2].fi - pref[pre]) * 2 + Sum[sz_sum - 1].fi;
                    ll value = max(l, r);
                    ans = max(ans, value);
                }
                else if (sz_max >= 2)
                {
                    ll value = (Max[sz_max - 2].fi - pref[pre]) * 2 + Sum[sz_sum - 1].fi;
                    ans = max(ans, value);
                }
                else if (sz_sum >= 2)
                {
                    ll value = (Max[sz_max - 1].fi - pref[pre]) * 2 + Sum[sz_sum - 2].fi;
                    ans = max(ans, value);
                }
            }
        }
    }
}

void init()
{
}

void solution()
{
    era();
    cin >> n;
    For(i, 1, n) cin >> s[i];
    For(i, 1, n) cin >> c[i], prime[i] = convert(c[i]);
    For(i, 1, n - 1)
    {
        ll x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs_max(1, 0);
    dfs_triple(1, 0);
    if(ans == -inf)
        cout << "No Solution\n";
    else
        cout << ans << endl;
}

main()
{
    // FILEIN;
    // FILEOUT;
    FAST;
    ll T = 1;
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
