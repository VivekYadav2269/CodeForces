#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector <int> dp(n + 1), at(n, -1);
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        x--;
        int j = at[x] == -1 ? i + 1 : at[x];
        dp[i + 1] = std::max(dp[i], dp[j] + i + 1 - j);
        if (dp[i] >= dp[j] + i + 1 - j) {
            at[x] = i;
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