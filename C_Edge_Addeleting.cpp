#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector adj(n, std::vector <int> ());
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    std::vector <int> dis(n);
    auto dfs = [&](auto& self, int u, int p, int d = 0) -> void {
        dis[u] = d;
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            self(self, v, u, d + 1);
        }
    };
    dfs(dfs, n - 1, -1);
    
    int min = n + 1, idx = -1;
    for (int v : adj[0]) {
        if (dis[v] < min) {
            min = dis[v];
            idx = v;
        }
    }
    
    std::vector <bool> sN(n);
    auto dfs1 = [&](auto& self, int u, int p) -> void {
        sN[u] = true;
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            self(self, v, u);
        }
    };
    dfs1(dfs1, idx, 0);
    
    int ans = dis[0];
    for (int i = 0; i < m; i++) {
        int x;
        std::cin >> x;
        x--;
        if (sN[x]) {
            ans = std::max(ans, dis[x] + 1);
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