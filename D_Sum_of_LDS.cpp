#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector <int> a(n);
    for (int i = 0; i < n; i++){
        std::cin >> a[i];
    }
    
    std::vector <i64> dp(n);
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        dp[i] = 1LL * (i + 1);
        if (a[i - 1] > a[i]) {
            dp[i] += dp[i - 1];
        } else if (i - 2 >= 0) {
            dp[i] += dp[i - 2];
        }
    }
    std::cout << accumulate(dp.begin(), dp.end(), 0LL) << '\n';
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
