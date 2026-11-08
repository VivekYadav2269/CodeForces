#include <bits/stdc++.h>
using i64 = long long;

const int mod = 998244353;

int Add(int x, int y) {
    x += y;
    if (x >= mod) {
        x -= mod;
    }
    return x;
}

void solve() {
   int n;
   std::cin >> n;
   
   std::vector <int> a(n);
   std::vector <bool> vis(3 * n + 10);
   for (int i = 0; i < n; i++) {
       std::cin >> a[i];
       vis[a[i]] = true;
   }
   
   i64 tw = 1LL * n * (n - 1) / 2;
   std::vector <std::array <int, 3>> dp(3 * n + 1, {0, 0, 0});
   int ans = Add(n, tw % mod);
   for (int i = 3; i <= 3 * n; i++) {
        if (!vis[i]) {
            continue;
        }
        
        if (vis[i - 3] && vis[i - 2]) {
            dp[i][0] = Add(Add(dp[i - 2][1], dp[i - 2][2]), 1);
        }
        if (vis[i - 3] && vis[i - 1]) {
            dp[i][1] = Add(dp[i - 1][0], 1);
        }
        if (vis[i - 2] && vis[i - 1]) {
            dp[i][2] = Add(dp[i - 1][1], 1); 
        }
        ans = Add(ans, dp[i][0]);
        ans = Add(ans, dp[i][1]);
        ans = Add(ans, dp[i][2]);
   }
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