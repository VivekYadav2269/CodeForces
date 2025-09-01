#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector adj(n, std::vector <int> ());
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    std::vector <int> nodes(n), P(n);
    std::vector d(n, std::vector <int> ());
    auto dfs = [&](auto& self, int u, int p, int depth) -> void {
        d[depth].push_back(u);
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            } 
            P[v] = u;
            self(self, v, u, depth + 1);
            nodes[u] += nodes[v] + 1;
        }
    };
    dfs(dfs, 0, -1, 0);
    
    std::vector <int> dp(n);
    for (int i = n - 1; i > 0; i--) {
        for (int u : d[i]) {
            dp[u] = nodes[u];
            for (int v : adj[P[u]]) {
                if (v == u) {
                    continue;
                }
                for (int j : adj[v]) {
                    if (j == P[u]) {
                        continue;
                    }
                    dp[u] = std::max(dp[u], nodes[u] + dp[j]);
                }
            }
        }
    }
    std::cout << *std::max_element(dp.begin(), dp.end()) << '\n';
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