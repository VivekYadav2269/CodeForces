#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    
    std::vector adj(n, std::vector <int> ());
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    std::vector <int> child(n);
    auto dfs = [&](auto& self, int u, int p) -> void {
        child[u] = 1;
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            self(self, v, u);
            child[u] += child[v];
        }
    };
    dfs(dfs, 0, -1);
    
    i64 ans = n;
    for (int i = 0; i < n; i++) {
        for (auto j : adj[i]) {
            if (child[j] > child[i]) {
                if (child[i] >= k) {
                    ans += n - child[i];
                }
            } else {
                if (n - child[j] >= k) {
                    ans += child[j];
                }
            }
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