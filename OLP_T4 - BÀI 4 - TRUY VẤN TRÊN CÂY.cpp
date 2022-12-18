#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

#define int long long;

#define For(i, a, b) for (ll i = (ll)a; i <= (ll)b; i++)
#define Ford(i, a, b) for (ll i = (ll)a; i >= (ll)b; i--)
#define vec vector
#define pb push_back
#define fi first
#define se second

const ll N = 2e5 + 5;
const ll mod = 1e9 + 7;
const ll oo = 1e18;



ll n;
vec<ll> g[N];
ll p[N];
ll first[N], final[N];
ll pre[N], suf[N];
ll bit[N];

void update(ll i)
{
    for (; i < N; i += i & -i)
        bit[i]++;
}
ll get(ll i)
{
    ll ans = 0;
    for (; i; i -= i & -i)
        ans += bit[i];
    return ans;
}

vec<ll> euler;

void dfs(ll u, ll pre)
{
    first[u] = euler.size();
    final[u] = euler.size();
    euler.pb(u);
    for (auto x : g[u])
    {
        if (x == pre)
            continue;
        dfs(x, u);
        final[u] = euler.size();
        euler.pb(u);
    }
}

bool vis[N];

void init()
{
}
void solution()
{
    cin >> n;
    vec<ll> a;
    For(i, 1, n) cin >> p[i], a.push_back(p[i]);
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    For(i, 1, n) p[i] = lower_bound(a.begin(), a.end(), p[i]) - a.begin() + 1;

    For(i, 1, n - 1)
    {
        ll x;
        cin >> x;
        g[x].pb(i + 1);
    }
    dfs(1, 0);
    For(i, 0, euler.size() - 1)
    {
        ll u = euler[i];
        if (i == first[u])
        {
            pre[u] = get(N - 1) - get(p[u]);
        }
        if (i == final[u])
        {
            suf[u] = get(N - 1) - get(p[u]);
        }
        if(!vis[u]){
            vis[u] = 1;
            update(p[u]);
        }
    }
    // For(i, 1, n) cout << first[i] << " " << final[i] << endl;
    For(i, 1, n) cout << suf[i] - pre[i] << endl;
}

main()
{
    ll T = 1;
    // cin >> T;
    For(test, 1, T)
    {
        // cout << "TEST " << test << ": \n";
        solution();
    }
}
