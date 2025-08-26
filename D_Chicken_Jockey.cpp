#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector <int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::vector <i64> dp(n);
    std::vector <i64> stk(n + 1);
    stk[n - 1] = 1;
    i64 ans = std::accumulate(a.begin(), a.end(), 0LL);
    for (int i = n - 2; i >= 0; i--) {
        dp[i] = std::max(std::min(a[i + 1], i + 1) + stk[i + 2], stk[i + 1]);
        stk[i] = std::max(dp[i], stk[i + 1] + 1);
    }
    
    ans -= dp[0];
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