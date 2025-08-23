#include <bits/stdc++.h>
using i64 = long long;

const int mod = 998244353;
const int N = 1E6 + 7;

int add(int x, int y) {
    x += y;
    if (x >= mod) {
        x -= mod;
    }
    return x;
}

int sub(int x, int y) {
    x -= y;
    if (x < 0) {
        x += mod;
    }
    return x;
}

void solve() {
    int n;
    std::cin >> n;
    
    std::vector adj(n, std::vector <int> ());
    for (int i = 0; i < n - 1; i++) {
        int x;
        std::cin >> x;
        x--;
        adj[i + 1].push_back(x);
        adj[x].push_back(i + 1);
    }
    
    std::vector <int> dep(n), cnt(n), a(n);
    std::vector node(n, std::vector <int> ());
    auto dfs = [&](auto& self, int u, int p, int depth) -> void {
        cnt[depth]++;
        dep[u] = depth;
        node[depth].push_back(u);
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            self(self, v, u, depth + 1);
        }
    };
    dfs(dfs, 0, -1, 0);
    
    std::vector <int> dp(n);
    for (int i = n - 2; i >= 0; i--) {
        for (int u : node[i]) {
            dp[u] = add(a[i + 1], cnt[i + 1]);
            if (i) {
                for (int v : adj[u]) {
                    if (dep[v] == i + 1) {
                        dp[u] = sub(dp[u], add(dp[v], 1));
                    }
                }
            }
            a[i] = add(a[i], dp[u]);
        }
    }
    std::cout << add(1, a[0]) << '\n';
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