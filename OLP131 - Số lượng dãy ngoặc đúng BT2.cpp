

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
using order_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using order_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
const ll inf = 1ll << 60;
const ll N = 1e2 + 5;

int di[] = {-1, 0, 0, 1, -1, -1, 1, 1};
int dj[] = {0, -1, 1, 0, -1, 1, -1, 1};

ll n, k;
ll dp[N][N][N];

ll solve(ll i, ll cnt, ll degree)
{
    ll &ans = dp[i][cnt][degree];
    if (dp[i][cnt][degree] != -1)
        return ans;
    ans = 0;
    if (i == n)
    {
        if (cnt == 0 && degree == k)
        {
            ans = 1;
        }
        return ans;
    }
    ans += solve(i + 1, cnt + 1, max(degree, cnt + 1));
    if (cnt)
        ans += solve(i + 1, cnt - 1, degree);
    return ans;
}

void init()
{
}

void solution()
{
    cin >> n >> k;
    memset(dp, 0, sizeof(dp));
    // dp[n][0][k] = 1;
    Ford(i, n, 0)
    {
        For(cnt, 0, n - 1)
        {
            For(degree, 0, n - 1)
            {
                ll &ans = dp[i][cnt][degree];
                if (i == n)
                {
                    if (cnt == 0 && degree == k)
                    {
                        ans = 1;
                    }
                    continue;
                }
                ans += dp[i + 1][cnt + 1][max(degree, cnt + 1)];
                if (cnt)
                {
                    ans += dp[i + 1][cnt - 1][degree];
                }
            }
        }
    }
    // cout << dp[0][0][0] << endl;
    ll ans = dp[0][0][0];
    string res = to_string(ans);
    if (res.size() <= 10)
    {
        cout << res << endl;
        return;
    }
    else
    {
        For(i, 0, 4) cout << res[i];
        cout << "...";
        For(i, res.size() - 5, res.size() - 1) cout << res[i];
        cout << endl;
    }
}

main()
{
    // FILEIN;
    // FILEOUT;
    FAST;
    ll T = 1;
    cin >> T;
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
