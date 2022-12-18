#include <iostream>
using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define pi pair<int, int>
#define st first
#define nd second

const int N = 1e6 + 7, I = 1e9 + 7;
int n, q, a[N], shift;

struct SumSegtree
{
    ll f[N << 1];

    void init()
    {
        for (int i = 0; i < n; i++)
            f[i + n] = a[i];
        for (int i = n - 1; i > 0; i--)
            f[i] = f[i << 1] + f[i << 1 | 1];
    }

    void upd(int i, ll v)
    {
        f[i += n] = v;
        for (i >>= 1; i > 0; i >>= 1)
            f[i] = f[i << 1] + f[i << 1 | 1];
    }

    ll get(int l, int r)
    {
        ll res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                res += f[l++];
            if (r & 1)
                res += f[--r];
        }
        return res;
    }
} sst;

struct MinSegtree
{
    pi f[N << 1];

    void init()
    {
        for (int i = 0; i < n; i++)
            // current position of `i` panel: (i + shift) % n
            f[i + n] = {a[i], i};
        for (int i = n - 1; i > 0; i--)
            f[i] = min(f[i << 1], f[i << 1 | 1]);
    }

    void upd(int i, int v)
    {
        f[i + n] = {v, i};
        for ((i += n) >>= 1; i > 0; i >>= 1)
            f[i] = min(f[i << 1], f[i << 1 | 1]);
    }

    pi get(int l, int r)
    {
        pi res = {I, I};
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                res = min(res, f[l++]);
            if (r & 1)
                res = min(res, f[--r]);
        }
        return res;
    }
} mst;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sst.init();
    mst.init();
    while (q--)
    {
        int t;
        cin >> t;
        switch (t)
        {
        case 1:
        {
            int d;
            cin >> d;
            shift = (shift + d) % n;
            break;
        }
        case 2:
        {
            int at_zero = (n - shift) % n; // the panel with this id is currently at position 0
            int s, e, p;
            cin >> s >> e >> p;
            s = (s - 1 - shift + n) % n;
            e = (e - 1 - shift + n) % n;
            pi replaced;
            if (s <= e)
            {
                // if zero is between of the query
                if (s <= at_zero && at_zero <= e)
                {
                    // the current position of `lef` is always bigger than `rig`
                    pi lef = mst.get(at_zero, e + 1);
                    pi rig = mst.get(s, at_zero);
                    // if value is equal --> choose the one on the left (the one which has lower position)
                    if (lef.st == rig.st)
                        replaced = lef;
                    else
                        replaced = min(lef, rig);
                }
                else
                {
                    replaced = mst.get(s, e + 1);
                }
            }
            else
            {
                if (e < at_zero && at_zero < s)
                {
                    // zero is at nowhere
                    pi lef = mst.get(s, n);
                    pi rig = mst.get(0, e + 1);
                    //
                    if (lef.st == rig.st)
                        replaced = lef;
                    else
                        replaced = min(lef, rig);
                }
                else if (s <= at_zero && at_zero < n)
                {
                    // zero is in [s:n)
                    pi lef = mst.get(at_zero, n);
                    pi rig = min(mst.get(0, e + 1), mst.get(s, at_zero));

                    //
                    if (lef.st == rig.st)
                        replaced = lef;
                    else
                        replaced = min(lef, rig);
                }
                else if (0 <= at_zero && at_zero <= e)
                {
                    // zero is in [0:e]
                    pi lef = min(mst.get(at_zero, e + 1), mst.get(s, n));
                    pi rig = mst.get(0, at_zero);
                    //
                    if (lef.st == rig.st)
                        replaced = lef;
                    else
                        replaced = min(lef, rig);
                }
            }
            mst.upd(replaced.nd, p);
            sst.upd(replaced.nd, p);
            break;
        }
        case 3:
        {
            int s, e;
            cin >> s >> e;
            s = (s - 1 - shift + n) % n;
            e = (e - 1 - shift + n) % n;
            if (s <= e)
            {
                cout << sst.get(s, e + 1) << "\n";
            }
            else
            {
                cout << sst.get(s, n) + sst.get(0, e + 1) << "\n";
            }
            break;
        }
        }
    }
    return 0;
}
