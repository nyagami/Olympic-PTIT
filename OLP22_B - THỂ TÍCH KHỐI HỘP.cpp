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
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
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
template <class T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
template <class T>
using maxpq = priority_queue<T, vector<T>>;
template <class A, class B>
using pq = priority_queue<A, vector<A>, B>;

typedef pair<ll, ll> ii;
typedef pair<ll, ii> i_ii;
typedef pair<ii, ll> ii_i;
typedef pair<ii, ii> ii_ii;
typedef pair<ll, char> ic;
typedef pair<char, ll> ci;
typedef pair<ll, string> is;
typedef pair<string, ll> si;
typedef pair<db, db> dd;
typedef vector<ii> vii;
typedef vector<ll> v;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<v> vv;

ll _max(ll a, ll b, ll c) { return max(a, max(b, c)); }
ll _min(ll a, ll b, ll c) { return min(a, min(b, c)); }

unordered_map<ll, ll> compress(vector<ll> u)
{
    vector<ll> sorted = u;
    sort(all(sorted));
    uniq(sorted);
    int l = sorted.size();
    unordered_map<ll, ll> m;
    for (int i = 0; i < l; i++)
        m[sorted[i]] = i;
    return m;
}

ll to_int(string s)
{
    ll ans = 0;
    for (auto x : s)
        ans = ans * 10 + (x - '0');
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
const ll oo = (ll)1 << 60;
const db PI = 3.14159265358979323846;
const ll N = 2e5 + 5;

int di[] = {-1, 0, 0, 1, -1, -1, 1, 1};
int dj[] = {0, -1, 1, 0, -1, 1, -1, 1};

struct node
{
    ll x, y, z;
};
struct edge
{
    node a, b;
} c[N], newc[N];

ll n;

ll dp[205][205][205];

void init()
{
}

void solution()
{
    cin >> n;
    v lsx, lsy, lsz;
    For(i, 1, n)
    {
        cin >> c[i].a.x >> c[i].a.y >> c[i].a.z;
        cin >> c[i].b.x >> c[i].b.y >> c[i].b.z;
        lsx.pb(c[i].a.x);
        lsy.pb(c[i].a.y);
        lsz.pb(c[i].a.z);
        lsx.pb(c[i].b.x);
        lsy.pb(c[i].b.y);
        lsz.pb(c[i].b.z);
    }
    // ll ans = 0;
    unordered_map<ll, ll> mx = compress(lsx);
    unordered_map<ll, ll> my = compress(lsy);
    unordered_map<ll, ll> mz = compress(lsz);

    ll valx[205] = {0};
    ll valy[205] = {0};
    ll valz[205] = {0};

    ll mnx = oo, mxx = -oo, mny = oo, mxy = -oo, mnz = oo, mxz = -oo;
    For(i, 1, n)
    {
        newc[i].a.x = mx[c[i].a.x];
        newc[i].a.y = my[c[i].a.y];
        newc[i].a.z = mz[c[i].a.z];

        newc[i].b.x = mx[c[i].b.x];
        newc[i].b.y = my[c[i].b.y];
        newc[i].b.z = mz[c[i].b.z];

        valx[newc[i].a.x] = c[i].a.x;
        valy[newc[i].a.y] = c[i].a.y;
        valz[newc[i].a.z] = c[i].a.z;

        valx[newc[i].b.x] = c[i].b.x;
        valy[newc[i].b.y] = c[i].b.y;
        valz[newc[i].b.z] = c[i].b.z;

        mxx = max(mxx, newc[i].b.x);
        mnx = min(mnx, newc[i].a.x);

        mxy = max(mxy, newc[i].b.y);
        mny = min(mny, newc[i].a.y);

        mxz = max(mxz, newc[i].b.z);
        mnz = min(mnz, newc[i].a.z);

        For(x, newc[i].a.x, newc[i].b.x - 1)
            For(y, newc[i].a.y, newc[i].b.y - 1)
                For(z, newc[i].a.z, newc[i].b.z - 1)
        {
            dp[x][y][z] = 1;
        }
    }
    ll ans = 0;
    For(x, mnx, mxx - 1)
    {
        For(y, mny, mxy - 1)
        {
            For(z, mnz, mxz - 1)
            {
                if (dp[x][y][z])
                {
                    // cout << x << " " << y << " " << z << endl;
                    // cout << m[x + 1] << " " << m[x] << endl;
                    // cout << (m[x + 1] - m[x]) * (m[y + 1] - m[y]) * (m[z + 1] - m[z]) << endl;
                    ans += abs(valx[x + 1] - valx[x]) * abs(valy[y + 1] - valy[y]) * abs(valz[z + 1] - valz[z]);
                }
            }
        }
    }
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
