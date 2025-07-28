#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, l;
    cin >> n >> m >> l;
    
    vector <int> a(l);
    for (int i = 0; i < l; i++) {
        cin >> a[i];
    }
    int sum = accumulate(a.begin(), a.end(), 0);
    const int inf = sum & 1 ? sum + 2 : sum + 1;
    int mn = inf;
    
    for (int i = 0; i < l; i++) {
        if (a[i] & 1) {
            mn = min(mn, a[i]);
        }
    }
    
    vector adj(n, vector <int> ());
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue <pair <int, int>> q;
    q.emplace(0, 0);
    vector <array <int, 2>> L(n, {inf + 1, inf});
    L[0][0] = 0;
    
    while(!q.empty()){
        auto [u, p] = q.front(); 
        q.pop();
        int d = L[u][p];
        
        for(int v : adj[u]){
            int np = p ^ 1;            
            if(L[v][np] > d + 1) {
                L[v][np] = d + 1;
                q.emplace(v, np);
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (sum & 1) {
            cout << ((L[i][1] < inf) || (L[i][0] <= sum - mn) ? "1" : "0");
        } else {
            cout << ((L[i][0] < inf) || (L[i][1] <= sum - mn) ? "1" : "0");
        }
    }
    cout << '\n';
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