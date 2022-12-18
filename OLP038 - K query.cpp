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
const ll oo = (ll)1 << 60;
const ll N = 2e5 + 5;

int di[] = {-1, 0, 0, 1, -1, -1, 1, 1};
int dj[] = {0, -1, 1, 0, -1, 1, -1, 1};

ll n, q;
ll f[N];

void update(ll idx, ll value)
{
    for (; idx < N; idx += idx & -idx)
        f[idx] += value;
}
ll get(ll idx)
{
    ll ans = 0;
    for (; idx; idx -= idx & -idx)
        ans += f[idx];
    return ans;
}

void init()
{
    fill(f, f + N, 0);
}

vec<tuple<ll, ll, ll, ll>> a;
ll ans[N];
void solution()
{
    cin >> n;
    For(i, 1, n)
    {
        ll x;
        cin >> x;
        a.pb({i, i, x, 0});
    }
    cin >> q;
    For(i, 1, q)
    {
        ll l, r, q;
        cin >> l >> r >> q;
        a.pb({l, r, q, i});
    }
    sort(all(a), [](tuple<ll, ll, ll, ll> x, tuple<ll, ll, ll, ll> y)
         {
        auto [l1, r1, s1, id1] = x;
        auto [l2, r2, s2, id2] = y;
        return (s1 > s2 || s1 == s2 && id1 > id2); });

    for (auto [l, r, x, id] : a)
    {
        // cout << l << " " << r << " " << x << " " << id << endl;
        if(id == 0)
            update(l, 1);
        else{
            ans[id] = get(r) - get(l - 1);
        }
    }
    For(i, 1, q) cout << ans[i] << "\n";
    cout << endl;
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
