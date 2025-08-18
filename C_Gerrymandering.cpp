#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::array <std::string, 2> s;
    std::cin >> s[0] >> s[1];
    
    auto cal = [&](char a, char b, char c) -> int {
        int res = (a == 'A') + (b == 'A') + (c == 'A');
        return res > 1 ? 1 : 0;
    };
    
    std::vector <std::array <int, 6>> dp(n + 1);
    for (int i = 1; i < n; i++) {
        if ((i + 1) % 3 == 2) {
            dp[i + 1][0] = std::max({dp[i - 1][1], dp[i - 1][3], dp[i - 1][4]});
            dp[i + 1][2] = std::max({dp[i - 1][1], dp[i - 1][3], dp[i - 1][4]});
            dp[i + 1][0] += cal(s[0][i - 1], s[1][i - 1], s[1][i]);
            dp[i + 1][2] += cal(s[0][i - 1], s[0][i], s[1][i - 1]);
        }
        if ((i + 1) % 3 == 0) {
            if (i > 4) {
                dp[i + 1][1] = dp[i][5];
                dp[i + 1][3] = dp[i][4];
            }
            dp[i + 1][1] = std::max(dp[i + 1][1], dp[i][0]) + cal(s[0][i - 1], s[0][i], s[1][i]);
            dp[i + 1][3] = std::max(dp[i + 1][3], dp[i][2]) + cal(s[1][i - 1], s[0][i], s[1][i]);
        }
        if (i > 1) {
            dp[i + 1][4] = dp[i - 2][4];
            dp[i + 1][5] = dp[i - 2][5];
            if ((i + 1) % 3 == 0) {
                dp[i + 1][4] = std::max({dp[i + 1][4], dp[i - 2][1], dp[i - 2][3]}) + cal(s[1][i - 2], s[1][i - 1], s[1][i]);
                dp[i + 1][5] = std::max({dp[i + 1][5], dp[i - 2][1], dp[i - 2][3]}) + cal(s[0][i - 2], s[0][i - 1], s[0][i]);
            } else if ((i + 1) % 3 == 1) {
                dp[i + 1][4] = std::max(dp[i + 1][4], dp[i - 1][0]);
                dp[i + 1][5] = std::max(dp[i + 1][5], dp[i - 1][2]);
                if (i > 5) {
                    dp[i + 1][4] = std::max(dp[i + 1][4], dp[i - 1][5]);
                    dp[i + 1][5] = std::max(dp[i + 1][5], dp[i - 1][4]);
                }
            } else {
                dp[i + 1][4] = dp[i][5];
                dp[i + 1][5] = dp[i][4];
            }
            dp[i + 1][4] += cal(s[0][i - 2], s[0][i - 1], s[0][i]);
            dp[i + 1][5] += cal(s[1][i - 2], s[1][i - 1], s[1][i]);
        }
    }
    
    int ans = 0;
    for (int i = 1; i < 6; i += 2) {
        ans = std::max(ans, dp[n][i]);
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}