#include <bits/stdc++.h>
using i64 = long long;

const int mod = 1E9 + 7;

int Add(int x, int y) {
    x += y;
    if (x >= mod) {
        x -= mod;
    }
    return x;
}

int Mul(int x, int y) {
    return 1LL * x * y % mod;
}

void solve() {
    int n;
    std::cin >> n;
    
    std::vector adj(n + 1, std::vector <int> ());
    adj[0].push_back(1);
    adj[1].push_back(0);
    for (int i = 1; i <= n; i++) {
        int l, r;
        std::cin >> l >> r;
        if (l == 0) {
            continue;
        }
        adj[i].push_back(l);
        adj[i].push_back(r);
        adj[l].push_back(i);
        adj[r].push_back(i);
    }
    
    std::vector <int> subTree(n + 1);
    auto dfs = [&](auto &self, int u, int p) -> void {
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            self(self, v, u);
            subTree[u] += subTree[v] + 1;
        }
    };
    dfs(dfs, 0, -1);
    
    std::vector <int> ans(n + 1);
    auto dfs1 = [&](auto &self, int u, int p) -> void {
        if (p != -1) {
            ans[u] = Add(ans[p], Add(1, Mul(2, subTree[u])));
        }
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            self(self, v, u);
        }
    };
    dfs1(dfs1, 0, -1);
    
    for (int i = 1; i <= n; i++) {
        std::cout << ans[i] << " \n"[i == n];
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