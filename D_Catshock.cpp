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
    
    std::vector <int> dep(n), par(n);
    auto dfs = [&](auto &self, int u, int p) -> void {
        par[u] = p;
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            dep[v] = dep[u] + 1;
            self(self, v, u);
        }
    };
    dfs(dfs, n - 1, -1);
    
    std::queue <int> q;
    std::vector <int> indegree(n);
    for (int i = 0; i < n; i++) {
        if (adj[i].size() == 1) {
            q.push(i);
        }
        indegree[i] = adj[i].size();
    }
    int now = dep[0] % 2;
    std::vector <std::array <int, 2>> ans;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (v == n - 1) {
            continue;
        }
        if (dep[v] % 2 == now) {
            ans.push_back({1, 0});
            ans.push_back({2, v});
            ans.push_back({1, 0});
        } else {
            ans.push_back({2, v});
            ans.push_back({1, 0});
            now ^= 1;
        }
        indegree[par[v]]--;
        if (indegree[par[v]] == 1) {
            q.push(par[v]);
        }
    }
    
    std::cout << ans.size() << '\n';
    for (auto a : ans) {
        std::cout << a[0] << ' ';
        if (a[0] == 2) {
            std::cout << a[1] + 1 << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
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