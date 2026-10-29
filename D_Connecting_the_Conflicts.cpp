#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int k;
    std::cin >> k;
    
    std::vector <std::vector <std::vector <int>>> forest(k);
    for (int i = 0; i < k; i++) {
        int n;
        std::cin >> n;
        
        std::vector adj(n, std::vector <int> ());
        for (int j = 0; j < n - 1; j++) {
            int u, v;
            std::cin >> u >> v;
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        forest[i] = adj;
    }
    
    auto dfs = [&](auto& self, int u, int p, std::vector <std::vector <int>>& adj, std::vector <std::array <int, 2>>& dp) -> void {
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            self(self, v, u, adj, dp);
            dp[u][0] += dp[v][1];
            dp[u][1] += std::max(dp[v][0], dp[v][1]);
        }
    };
    
    std::vector <std::array <int, 2>> cnt(k, {0, 0});
    int idx = -1;
    for (int i = 0; i < k; i++) {
        if (forest[i].size() > 1) {
            idx = i;
        }
        std::vector <std::array <int, 2>> dp(forest[i].size(), {1, 0});
        dfs(dfs, 0, -1, forest[i], dp);
        cnt[i][0] = dp[0][0];
        cnt[i][1] = dp[0][1];
    }
    
    if (idx == -1) {
        for (int i = 1; i < k; i++) {
            std::cout << "1 1 " << i + 1 << ' ' << "1\n";
        }
        return;
    }
    
    for (int i = 0; i < k; i++) {
        if (i == idx) {
            continue;
        }
        bool ok = false;
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                if (j != k && cnt[idx][j] >= cnt[idx][k] && cnt[i][j] >= cnt[i][k]) {
                    ok = true;
                }
            }
        }
        if (ok) {
            std::cout << idx + 1 << ' ' << forest[idx][0][0] + 1 << ' ' << i + 1 << ' ' << "1\n";
        } else {
            std::cout << idx + 1 << ' ' << 1 << ' ' << i + 1 << ' ' << "1\n";
        }
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