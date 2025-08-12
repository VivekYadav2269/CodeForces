#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

vector<int> minp, primes, notprime;

void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();
    // ps.resize(n + 1);
    
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }
        
        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                break;
            }
        }
    }
    // for (int i = 2; i <= n; i++) {
    //     ps[i] = ps[i / minp[i]] + 1;
    // }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    sieve(4E5 + 1);
    for (int i = 1, j = 0; i <= 4E5; i++) {
        if (i == primes[j]) {
            j++;
            continue;
        }
        notprime.push_back(i);
    }
    
    while (t--) {
        int n;
        cin >> n;
        
        vector <vector <int>> adj(n);
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector <int> ans(n);
        vector <bool> vis(n);
        int cur = 1;
        auto dfs = [&](auto self, int i) -> void {
            vis[i] = true;
            ans[i] = cur;
            for (int j : adj[i]) {
                if (!vis[j]) {
                    int check = upper_bound(notprime.begin(), notprime.end(), cur - ans[i]) - notprime.begin();
      
                    cur = notprime[check] + ans[i];
                    self(self, j);
                }
            }
        };
        dfs(dfs, 0);
        
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " \n"[i == n - 1];
        }
    }
    
    return 0;
}