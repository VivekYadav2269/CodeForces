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
    
    std::vector <int> dep(n), max(n), cont(n), sum(n);
    auto dfs = [&](auto &self, int u, int p) -> void {
        if (adj[u].size() == 1) {
            max[u] = dep[u];
        }
        
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            dep[v] = dep[u] + 1;
            self(self, v, u);
            max[u] = std::max(max[u], max[v]);
            cont[u] += cont[v] + 1;
        }
        sum[dep[u]] += cont[u];
    };
    dfs(dfs, 0, -1);
    
    std::map <int, int> m;
    for (int i = 0; i < n; i++) {
        m[max[i]]++;
    }
    std::vector <int> has(n);
    for (int i = 1; i < n; i++) {
        has[i] += has[i - 1] + m[i - 1];
    }

    int ans = 1 << 30;
    int mx = *std::max_element(dep.begin(), dep.end());
    for (int i = 0; i <= mx && i < n; i++) {
        ans = std::min(ans, has[i] + sum[i]);
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