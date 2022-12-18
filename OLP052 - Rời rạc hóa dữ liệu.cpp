#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e3 + 5;
struct Floor
{
    int value;
    int id;
};

bool compare(Floor x, Floor y)
{
    if (x.value == y.value)
        return x.id < y.id;
    return x.value < y.value;
}
int parent[1000006] = {};
int FindSet(int x)
{
    if (parent[x] == x)
        return x;
    parent[x] = FindSet(parent[x]);
    return FindSet(parent[x]);
}

void Union(int u, int v)
{
    int parentU = FindSet(u);
    int parentV = FindSet(v);
    if (parentU == parentV)
    {
        return;
    }
    if (parentU > parentV)
        parent[parentU] = parentV;
    else
        parent[parentV] = parentU;
}

int main()
{
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int x;
    vector<int> adj[n * m + 1];
    Floor A[n + 1][m + 1];
    for (int i = 0; i < n * m; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> A[i][j].value;
            A[i][j].id = i * m + j;
        }
    }
    Floor check[max(n, m) + 1];
    int deg[n * m + 1] = {};
    // check dau bang
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            check[j] = A[i][j];
        }
        sort(check, check + m, compare);
        for (int j = 0; j < m - 1; j++)
        {
            if (check[j].value == check[j + 1].value)
            {
                Union(check[j].id, check[j + 1].id);
            }
        }
    }
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            check[i] = A[i][j];
        }
        sort(check, check + n, compare);
        for (int i = 0; i < n - 1; i++)
        {
            if (check[i].value == check[i + 1].value)
            {
                Union(check[i].id, check[i + 1].id);
            }
        }
    }
    // tao cac
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            check[j] = A[i][j];
        }
        sort(check, check + m, compare);
        for (int j = 0; j < m - 1; j++)
        {
            if (check[j].value == check[j + 1].value)
                continue;
            adj[FindSet(check[j].id)].push_back(FindSet(check[j + 1].id));
            deg[FindSet(check[j + 1].id)]++;
        }
    }
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            check[i] = A[i][j];
        }
        sort(check, check + n, compare);
        for (int i = 0; i < n - 1; i++)
        {
            if (check[i].value == check[i + 1].value)
                continue;
            adj[FindSet(check[i].id)].push_back(FindSet(check[i + 1].id));
            deg[FindSet(check[i + 1].id)]++;
        }
    }
    // check
    // topo sort
    // for(int i = 0; i < n * m; i++)
    // {
    //     cout << i << " " << FindSet(i) << " ";
    // }
    // cout << '\n';
    queue<int> Q = {};
    int newID[m * n + 1] = {};
    int dp[m * n + 1] = {};
    int Size = 0;
    for (int i = 0; i < m * n; i++)
    {
        if (deg[i] == 0 && FindSet(i) == i)
        {
            Q.push(i);
        }
    }
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        newID[Size++] = u;
        for (int v : adj[u])
        {
            if (--deg[v] == 0)
                Q.push(v);
        }
    }
    //
    int res = -1;
    for (int i = 0; i < Size; i++)
    {
        int u = newID[i];
        //  cout << u << ": ";
        for (int v : adj[u])
        {
            dp[v] = max(dp[v], dp[u] + 1);
            res = max(res, dp[v]);
            // cout << v << " ";
        }
        //  cout << dp[u] << "\n";
    }
    cout << res + 1;
}
