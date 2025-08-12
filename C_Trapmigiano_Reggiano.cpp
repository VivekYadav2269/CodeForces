#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, st, en;
    cin >> n >> st >> en;
    en--;
    
    vector <vector <int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector <int> ans;
    auto dfs = [&](auto &&self, int u, int p) -> void {
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            self(self, v, u);
            // ans.push_back(v);
        }
        ans.push_back(u);
    };
    dfs(dfs, en, -1);
    
    // reverse(ans.begin(), ans.end());
    // ans.push_back(en);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] + 1 << " \n"[i == ans.size() - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    return 0;
}