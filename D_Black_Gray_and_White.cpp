#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector adj(n + 1, std::vector <int> ());
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    if (n % 2 == 0) {
        std::cout << n + 1 << '\n';
        return;
    }
    
    auto dfs = [&](auto& self, int u, int p, std::set <int>& st, const int N) -> void {
        if (st.contains(N - u)) {
            st.erase(N - u);
        } else {
            st.insert(u);
        }
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            self(self, v, u, st, N);
        }
    };
    
    std::vector <std::array <int, 2>> b = {{n, n}, {(n + 1) / 2, n + 1}};
    for (auto bb : b) {
        std::set <int> St;
        std::size_t cnt = 0;
        for (int v : adj[bb[0]]) {
            std::set <int> st;
            dfs(dfs, v, bb[0], st, bb[1]);
            cnt += st.size();
        }
        
        if (cnt != 0) {
            std::cout << bb[1] << '\n';
            return;
        }
    }
    std::cout << n + 2 << '\n';
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