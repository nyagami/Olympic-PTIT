#include <bits/stdc++.h>
using namespace std;
long long dp[45][101][10] = {}; // f(so chu so, phan du, ket thuc bang so j, pos)
long long newDp[45][101] = {};
typedef long long ll;
#define FOR(i, m, n) for (int i = m; i <= n; i++)
#define FORD(i, n, m) for (int i = n; i >= m; i--)
ll Mod[45] = {};

int main()
{
    int n, m;
    unsigned long long k;
    while (cin >> n >> m >> k)
    {
        memset(dp, 0, sizeof(dp));
        dp[0][0][0] = 1;
        dp[1][0][0] = 1; // so 0
        FOR(i, 1, 9)
        {
            dp[1][i % m][i] = 1;
        }

        Mod[0] = 1 % m;
        FOR(i, 1, n)
        {
            Mod[i] = Mod[i - 1] * 10 % m;
        }
        FOR(i, 0, n - 2) // so chu so
        {
            FOR(sum, 0, m - 1) // phan du
            {
                {
                    FOR(lastDigit, 0, 9)
                    { // last digit
                        unsigned long long cur = dp[i][sum][lastDigit];
                        if (!cur)
                            continue;
                        FOR(digit, 0, 9)
                        {
                            ll newSum = (digit * Mod[i + 1] % m // digit * 10^(i+1)
                                         + sum * Mod[1] % m + digit) %
                                        m; // 10 + digit
                            dp[i + 2][newSum][digit] += cur;
                        }
                    }
                }
            }
        }
        ll ans = 0;
        FOR(i, 1, 9)
        ans = ans + dp[n][0][i];
        cout << ans << '\n';

        string res = "";
        string tmp = "";
        vector<int> s = {0};
        // cout << dp[2][5][1] << '\n';
        for (int i = n; i > 0; i -= 2)
        {
            int digit = 0;
            if (i == n)
                digit++;
            //        if( i== 1)
            //        {
            //            FOR(digit, 0 ,9)
            //            {
            //                if(check(digit, s, m))
            //                {
            //                    k--;
            //                }
            //                if(k == 0)
            //                {
            //                    tmp += digit + 48;
            //                    break;
            //                }
            //            }
            //            break;
            //        }
            vector<int> newS = {};
            while (digit < 10)
            {
                ll all = 0;
                for (auto e : s)
                {
                    all += dp[i][e][digit];
                    // cout << dp[i][e][digit] << " ";
                }
                // cout << '\n';
                for (auto e : s)
                {
                    // ll newMod = (e + m * 20 - digit * Mod[i-1] % m - digit % m ) % m;
                    // count all
                    FOR(mod, 0, m - 1)
                    {
                        if ((mod * 10 % m + digit * Mod[i - 1] % m + digit % m) % m == e)
                        {
                            // all += dp[i][mod][digit];
                            newS.push_back(mod);
                        }
                    }
                }
                // dieu kien
                // cout << k << " " << all << " " <<digit << '\n';
                if (all >= k)
                    break;

                k -= all;
                digit++;
                newS.clear();
            }
            // cout << '\n';
            s = newS;
            //        for(auto e: s) cout << e << " ";
            //        cout << '\n';
            if (i == 1)
                tmp += (digit + 48);
            else
                res += (digit + 48);
            // cout << digit << " ";
        }
        cout << res << tmp;
        reverse(res.begin(), res.end());
        cout << res << '\n';
        // cout << ULLONG_MAX;
    }
}
