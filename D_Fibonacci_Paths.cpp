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
    int n, m;
    std::cin >> n >> m;
    
    std::vector <i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::vector adj(n, std::vector <int> ());
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
    }
    
    std::vector <int> ord(n);
    std::iota(ord.begin(), ord.end(), 0);
    std::sort(ord.begin(), ord.end(), [&](int i, int j) {
        return a[i] < a[j];
    });
    
    std::vector <std::map <i64, int>> dp(n);
    for (int i = 0; i < n; i++) {
        for (int j : adj[i]) {
            dp[j][a[i]] = Add(dp[j][a[i]], 1);
        }
    }
    
    for (int i = 0; i < n; i++) {
        int u = ord[i];
        for (int v : adj[u]) {
            if (dp[u].contains(a[v] - a[u])) {
                dp[v][a[u]] = Add(dp[v][a[u]], dp[u][a[v] - a[u]]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (auto [_, x] : dp[i]) {
            ans = Add(ans, x);
        }
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