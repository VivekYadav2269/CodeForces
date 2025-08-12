#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;
    
    vector adj(n, vector <int> ());
    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    multiset <int> s;
    for (int i = 0; i < n; i++) {
        s.insert(adj[i].size());
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        s.extract(adj[i].size());
        for (int v : adj[i]) {
            s.extract(adj[v].size());
            ans = max(ans, (int)adj[i].size() + (int)adj[v].size() - 2);
        }
        
        if (!s.empty()) {
            int v = *s.rbegin();
            ans = max(ans, (int)adj[i].size() + v - 1);
        }
        s.insert(adj[i].size());
        for (int v : adj[i]) {
            s.insert(adj[v].size());
        }
    }
    
    cout << ans << '\n';
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