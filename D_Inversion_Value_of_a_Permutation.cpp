#include <bits/stdc++.h>
using i64 = long long;

std::vector <std::pair <int, std::vector <int>>> dp(436, {31, {}});


void f() {
    dp[0] = {0, {}};
    for (int i = 2; i <= 30; i++) {
        dp[i * (i - 1) / 2] = {i, {i}};
    }
    for (int i = 1; i < 436; i++) {
        if (dp[i].first == 31) {
            for (int j = 1; j < 436; j++) {
                for (int k = j; k < 436; k++) {
                    if (j + k == i && dp[j].first + dp[k].first < dp[i].first) {
                        dp[i] = {dp[j].first + dp[k].first, {}};
                        for (int x : dp[k].second) {
                            dp[i].second.push_back(x);
                        }
                        for (int x : dp[j].second) {
                            dp[i].second.push_back(x);
                        }
                    }
                }
            }
        }
    }
}

void solve() {
    int n, k;
    std::cin >> n >> k;
    
    k = n * (n - 1) / 2 - k;
    if (dp[k].first > n) {
        std::cout << 0 << '\n';
        return;
    }
    
    int inv = dp[k].first;
    for (int i = n; i > inv; i--) {
        std::cout << i << ' ';
        n--;
    }
    for (int x : dp[k].second) {
        for (int i = n - x + 1; i <= n; i++) {
            std::cout << i << ' ';
        }
        n -= x;
    }
    std::cout << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
   
    f();
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}