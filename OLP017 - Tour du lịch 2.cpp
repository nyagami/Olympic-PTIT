#include <bits/stdc++.h>

using namespace std;
#define fi first
#define se second
#define vec vector
#define pb push_back
#define For(i, a, b) for (int i = a; i <= b; i++)
#define Ford(i, a, b) for (int i = a; i >= b; i--)

typedef pair<long long, int> ii;

const long long oo = 1e18;
const int N = 1e3 + 5;
const int maxn = 1e6;

namespace IO
{
    const int BUFFER_SIZE = 1 << 15;

    char input_buffer[BUFFER_SIZE];
    int input_pos = 0, input_len = 0;

    void _update_input_buffer()
    {
        input_len = fread(input_buffer, sizeof(char), BUFFER_SIZE, stdin);
        input_pos = 0;

        if (input_len == 0)
            input_buffer[0] = EOF;
    }

    inline char next_char(bool advance = true)
    {
        if (input_pos >= input_len)
            _update_input_buffer();

        return input_buffer[advance ? input_pos++ : input_pos];
    }

    template <typename T>
    inline void read_int(T &number)
    {
        bool negative = false;
        number = 0;

        while (!isdigit(next_char(false)))
            if (next_char() == '-')
                negative = true;

        do
        {
            number = 10 * number + (next_char() - '0');
        } while (isdigit(next_char(false)));

        if (negative)
            number = -number;
    }

    template <typename T, typename... Args>
    inline void read_int(T &number, Args &...args)
    {
        read_int(number);
        read_int(args...);
    }
}

int n, m, k, last;
long long dist[N][N];
long long dp[maxn][20];
long long two[20];
bool check[N];
int a[20];
long long ans = oo;
vec<ii> g[N];

struct cmp
{
    bool operator()(ii x, ii y)
    {
        return x.fi > y.fi;
    }
};

void dijkstra(int u)
{
    For(i, 1, n) dist[u][i] = oo;
    dist[u][u] = 0;
    priority_queue<ii, vec<ii>, cmp> pq;
    pq.push({0, u});
    while (pq.size())
    {
        int it = pq.top().se;
        pq.pop();
        for (ii x : g[it])
        {
            int nxt = x.se;
            long long it_to_nxt = x.fi;
            if (dist[u][it] + it_to_nxt < dist[u][nxt])
            {
                dist[u][nxt] = it_to_nxt + dist[u][it];
                pq.push({dist[u][nxt], nxt});
            }
        }
    }
}

void solve()
{
    queue<ii> q;
    q.push({1, 1});
    dp[1][1] = 0;
    while (q.size())
    {
        ii u = q.front();
        q.pop();
        if (dp[u.fi][u.se] >= ans)
            continue;
        if (u.fi == last)
        {
            ans = min(ans, dp[u.fi][u.se] + dist[a[u.se]][1]);
            continue;
        }

        For(i, 2, k)
        {
            int r = two[i - 1];
            if ((u.fi & r) == 0)
            {
                int x = u.fi ^ r;
                if (dp[x][i] == oo)
                {
                    dp[x][i] = dp[u.fi][u.se] + dist[a[u.se]][a[i]];
                    q.push({x, i});
                }
                else
                {
                    dp[x][i] = min(dp[x][i], dp[u.fi][u.se] + dist[a[u.se]][a[i]]);
                }
            }
        }
    }
    printf("%lld\n", (ans == oo ? -1 : ans));
}

void init()
{
    two[0] = 1;
    For(i, 1, 19) two[i] = two[i - 1] * 2;
    last = two[k] - 1;
    For(i, 1, last)
    {
        For(j, 0, k) dp[i][j] = oo;
    }
}

int main()
{
    IO ::read_int(n, m, k);
    a[1] = 1;
    k += 1;
    For(i, 2, k) IO::read_int(a[i]);
    init();
    For(i, 1, m)
    {
        int x, y;
        long long w;
        IO ::read_int(x, y, w);
        g[x].pb({w, y});
    }
    For(i, 1, k) dijkstra(a[i]);
    solve();
}
