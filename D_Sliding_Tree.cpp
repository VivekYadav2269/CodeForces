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
    
    if (n == 1) {
        std::cout << -1 << '\n';
        return;
    }
    
    std::vector <int> dep(n);
    auto dfs = [&](auto& self, int u, int p) -> void {
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            dep[v] = dep[u] + 1;
            self(self, v, u);
        }
    };
    dfs(dfs, 0, -1);
    
    int a = std::max_element(dep.begin(), dep.end()) - dep.begin();
    std::fill(dep.begin(), dep.end(), 0);
    std::vector <int> max(n);
    auto dfs1 = [&](auto& self, int u, int p) -> void {
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
        }
        
    };
    dfs1(dfs1, a, -1);
    
    int b = adj[a][0];
    while (adj[b].size() <= 2) {
        int A = b;
        for (int v : adj[b]) {
            if (v != a) {
                b = v;
                break;
            }
        }
        if (A == b) {
            std::cout << -1 << '\n';
            return;
        }
        a = A;
    }
    
    int c, min = 1 << 30;
    for (int v : adj[b]) {
        if (v != a && min > max[v]) {
            c = v;
            min = max[v];
        }
    }
    std::cout << a + 1 << ' ' << b + 1 << ' ' << c + 1 << '\n';
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