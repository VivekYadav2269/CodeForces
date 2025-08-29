#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector <int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::vector A(n + 1, std::vector <int> ());
    std::vector <int> dp(n + 1);
    for (int i = 0; i < n; i++) {
        dp[i + 1] = dp[i];
        A[a[i]].push_back(i);
        int x = A[a[i]].size();
        if (x >= a[i]) {
            dp[i + 1] = std::max(dp[i + 1], dp[A[a[i]][x - a[i]]] + a[i]);
        }
    }
    std::cout << dp[n] << '\n';
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