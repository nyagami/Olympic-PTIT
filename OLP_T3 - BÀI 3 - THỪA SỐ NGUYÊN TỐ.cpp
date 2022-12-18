/* Created by Tran Duc Huy */

#include <bits/stdc++.h>

using namespace std;

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



typedef vector<ll> v;


const ll oo = 1e9;
const ll N = 1e6 + 5;



ll p, k;
ll e[N];
v prime, a;

void era()
{
    For(i, 2, N - 1) e[i] = i;
    for (ll i = 2; i * i < N; i++)
    {
        if (e[i] == i)
        {
            for (ll j = i * i; j < N; j += i)
                e[j] = i;
        }
    }
    For(i, 2, N - 1) if (e[i] == i) prime.pb(i);
}
bool check(int x)
{
    for (int i = 0; i < prime.size() && prime[i] * prime[i] <= x && prime[i] < p; i ++)
    {
        if (x % prime[i] == 0)
            return 0;
    }
    return 1;
}
ll solve(ll limit)
{
    ll s = limit / p;
    ll sum = 0;
    ll last = 1 << (ll)a.size();
    for (ll x = 1; x < last; x++)
    {
        ll g = p, cnt = 0;
        for (ll bit = 0; bit < a.size(); bit++){
            if(x >> bit & 1){
                cnt++;
                g *= a[bit];
            }
        }
        sum += (cnt % 2 ? 1 : -1) * (limit / g);
    }
    return s - sum;
}

void subtask1()
{
    for (ll i = 0; i < prime.size() && prime[i] < p; i++)
        a.pb(prime[i]);
    ll ans = 0;
    ll l = 1, r = 1e9;
    while (l <= r)
    {
        ll m = (l + r) / 2;
        ll s = solve(m);
        if(s >= k){
            ans = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    cout << ans << endl;
}

void subtask2()
{
    int cnt = 1;
    if (k == 1)
    {
        cout << p << endl;
        return;
    }
    for (int i = p; i >= 0; i++)
    {
        if (i == 1)
            cnt++;
        if (check(i))
            cnt++;
        if (p * i > oo)
        {
            cout << 0 << endl;
            return;
        }
        if (cnt == k)
        {
            cout << p * i << endl;
            return;
        }
    }
}

void init()
{
}

void solution()
{
    era();
    cin >> k >> p;
    // subtask2();
    if (p <= 50)
    {
        subtask1();
    }
    else
    {
        subtask2();
    }
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
