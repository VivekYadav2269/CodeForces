#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector <int> a(n), c(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> c[i];
    }
    
    std::vector <i64> dp(n);
    for (int i = 0; i < n; i++) {
        dp[i] = c[i];
        for (int j = i - 1; j >= 0; j--) {
            if (a[j] <= a[i]) {
                dp[i] = std::max(dp[i], dp[j] + c[i]);
            }
        }
    }
    std::cout << std::accumulate(c.begin(), c.end(), 0LL) - *std::max_element(dp.begin(), dp.end()) << '\n';
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