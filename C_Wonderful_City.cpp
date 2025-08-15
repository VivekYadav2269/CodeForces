#include <bits/stdc++.h>
using i64 = long long;

const i64 inf = 1E13;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector h(n, std::vector <int> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> h[i][j];
        }
    }
    
    std::vector <int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    
    i64 r = inf, c = inf;
    {
        std::vector <std::array <i64, 2>> dp(n);
        dp[0][0] = 0, dp[0][1] = a[0];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (h[i - 1][j] == h[i][j]) {
                    dp[i][0] = inf;
                }
            }
            if (dp[i][0] < inf) {
                dp[i][0] = dp[i - 1][0];
            }
            i64 res = 0;
            for (int j = 0; j < n; j++) {
                if (h[i - 1][j] + 1 == h[i][j]) {
                    res = inf;
                }
            }
            if (res < inf) {
                res = dp[i - 1][1];
            }
            dp[i][0] = std::min(dp[i][0], res);
            for (int j = 0; j < n; j++) {
                if (h[i - 1][j] == h[i][j] + 1) {
                    dp[i][1] = inf;
                }
            }
            if (dp[i][1] < inf) {
                dp[i][1] = dp[i - 1][0] + a[i];
            }
            res = 0;
            for (int j = 0; j < n; j++) {
                if (h[i - 1][j] == h[i][j]) {
                    res = inf;
                }
            }
            if (res < inf) {
                res = dp[i - 1][1] + a[i];
            }
            dp[i][1] = std::min(dp[i][1], res);
        }
        r = std::min(dp[n - 1][0], dp[n - 1][1]);
    }
    {
        std::vector <std::array <i64, 2>> dp(n);
        dp[0][0] = 0, dp[0][1] = b[0];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (h[j][i - 1] == h[j][i]) {
                    dp[i][0] = inf;
                }
            }
            if (dp[i][0] < inf) {
                dp[i][0] = dp[i - 1][0];
            }
            i64 res = 0;
            for (int j = 0; j < n; j++) {
                if (h[j][i - 1] + 1 == h[j][i]) {
                    res = inf;
                }
            }
            if (res < inf) {
                res = dp[i - 1][1];
            }
            dp[i][0] = std::min(dp[i][0], res);
            for (int j = 0; j < n; j++) {
                if (h[j][i - 1] == h[j][i] + 1) {
                    dp[i][1] = inf;
                }
            }
            if (dp[i][1] < inf) {
                dp[i][1] = dp[i - 1][0] + b[i];
            }
            res = 0;
            for (int j = 0; j < n; j++) {
                if (h[j][i - 1] == h[j][i]) {
                    res = inf;
                }
            }
            if (res < inf) {
                res = dp[i - 1][1] + b[i];
            }
            dp[i][1] = std::min(dp[i][1], res);
        }
        c = std::min(dp[n - 1][0], dp[n - 1][1]);
    }
    
    if (r > 1E12 || c > 1E12) {
        std::cout << -1 << '\n';
    } else {
        std::cout << r + c << '\n';
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