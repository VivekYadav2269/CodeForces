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
    
    std::vector <int> cnt(n);
    std::vector <int> leaf;
    int k = 0;
    for (int i = 0; i < n; i++) {
        if ((int)adj[i].size() == 1) {
            leaf.push_back(i);
            cnt[adj[i][0]]++;
        } else {
            k++;
        }
    }
    
    if (k < 2) {
        std::cout << 0 << '\n';
        return;
    }
    
    int ans = (int)leaf.size();
    ans -= *std::max_element(cnt.begin(), cnt.end());
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