#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector <int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::vector <bool> dp(2048);
    std::vector <int> max(n, -1);
    dp[a[n - 1]] = true;
    dp[0] = true;
    max[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        std::vector <bool> ndp = dp;
        for (int j = 0; j < 2048; j++) {
            if (dp[j]) {
                if ((a[i] ^ j) <= max[i + 1]) {
                    max[i] = std::max(max[i], a[i] ^ j);
                }
                ndp[a[i] ^ j] = true;
            }
        }
        dp = ndp;
    }
    
    for (int i = 0; i < n; i++) {
        if (max[i] == -1) {
            std::cout << "-1\n";
            return;
        }
    }
    
    for (int i = 0; i < n; i++) {
        std::cout << max[i] << " \n"[i == n - 1];
    }
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