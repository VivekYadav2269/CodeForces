#include <bits/stdc++.h>
using i64 = long long;

const i64 inf = 1E18;

void solve() {
    int n;
    i64 x, y;
    std::cin >> n >> x >> y;
    x <<= 1;
    y <<= 1;
    
    std::string a, b;
    std::cin >> a >> b;
    
    std::vector <int> at;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            at.push_back(i);
        }
    }
    
    int m = at.size();
    if (m % 2) {
        std::cout << "-1\n";
        return;
    }
    
    if (m == 0) {
        std::cout << "0\n";
        return;
    }
    
    std::vector <i64> dp(m, inf);
    dp[0] = y / 2;
    if (at[0] + 1 == at[1]) {
        dp[1] = std::min(x, y * 2);
    } 
    if (m > 2 || dp[1] == inf) {
        dp[1] = std::min({dp[1], y, x * (at[1] - at[0])});
    }
    for (int i = 2; i < m; i++) {
        if (at[i - 1] + 1 == at[i]) {
            dp[i] = std::min(dp[i - 1] + y / 2, dp[i - 2] + y * 2);
        }
        dp[i] = std::min({dp[i], dp[i - 1] + y / 2, dp[i - 2] + x * (at[i] - at[i - 1])});
    }
    std::cout << dp[m - 1] / 2 << '\n';
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