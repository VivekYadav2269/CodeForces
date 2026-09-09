#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::string s;
    std::cin >> s;
    
    if (s.find("00") != std::string::npos || s[0] == '0') {
        std::cout << "-1\n";
        return;
    }
    
    const int inf = 1E9;
    std::vector dp(n, std::array <int, 7> {inf, inf, inf, inf, inf, inf, inf});
    std::array <int, 7> M = {-3, -2, -1, 0, 1, 2, 3};
    
    if (s[0] == '+') {
        dp[0][4] = 1;
        dp[0][5] = 2;
        dp[0][6] = 3;
    } else {
        dp[0][0] = 3;
        dp[0][1] = 2;
        dp[0][2] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 7; j++) {
            bool pos = s[i] == '+' && M[j] > 0;
            bool neg = s[i] == '-' && M[j] < 0;
            bool zero = s[i] == '0' && M[j] == 0;
            if (pos || neg || zero) {
                for (int k = 0; k < 7; k++) {
                    if (j == k) {
                        continue;
                    }
                    dp[i][j] = std::min(dp[i][j], std::max(dp[i - 1][k], abs(j - k)));
                }
            }
        }
    }
    std::cout << *std::min_element(dp[n - 1].begin(), dp[n - 1].end()) << '\n';
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