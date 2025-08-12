#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    
    std::vector <int> a(n);
    std::vector ord(n, std::vector <int> ());
    std::set <int> s;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i]--;
        ord[(a[i] % (n + 1) + (n + 1)) % (n + 1)].push_back(i);
        s.insert(i);
    }
    
    std::vector <int> ans(n);
    std::vector <bool> vis(n + 1, false);
    int l = 1, r = n;
    for (int i = 0; !ord[i].empty() && i < n - 1; i++) {
        int k = l + ord[i].size() - 1;
        
        if ((i & 1) && ord[i][0] == *s.begin()) {
            int p = 0;
            s.erase(*s.begin());
            
            while (p + 1 < ord[i].size() && ord[i][p + 1] == *s.begin()) {
                p++;
                s.erase(*s.begin());
            }
            
            for (int j = p + 1; j < ord[i].size(); j++, l++) {
                ans[ord[i][j]] = k - j;
                vis[ans[ord[i][j]]] = true;
                s.erase(ord[i][j]);
            }
            for (int j = p; j >= 0; j--, l++) {
                ans[ord[i][j]] = k + j - p;
                vis[ans[ord[i][j]]] = true;
            }
        } else if ((i & 1 ^ 1) && ord[i][(int)ord[i].size() - 1] == *s.rbegin()) {
            int p = ord[i].size() - 1;
            s.erase(*s.rbegin());
            
            while (p - 1 >= 0 && ord[i][p - 1] == *s.rbegin()) {
                p--;
                s.erase(*s.rbegin());
            }
            
            for (int j = 0; j < p; j++, r--) {
                ans[ord[i][j]] = r;
                vis[ans[ord[i][j]]] = true;
                s.erase(ord[i][j]);
            }
            for (int j = ord[i].size() - 1; j >= p; j--, r--) {
                ans[ord[i][j]] = r;
                vis[ans[ord[i][j]]] = true;
            }
        } else {
            for (int j = 0; j < ord[i].size(); j++) {
                if (i & 1) {
                    ans[ord[i][j]] = k - j;
                    vis[ans[ord[i][j]]] = true;
                    s.erase(ord[i][j]);
                    l++;
                } else {
                    ans[ord[i][j]] = r;
                    vis[ans[ord[i][j]]] = true;
                    s.erase(ord[i][j]);
                    r--;
                }
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            ans[ord[n - 1][0]] = i;
            break;
        }
    }
    
    for (int i = 0; i < n; i++) {
        std::cout << ans[i] << " \n"[i == n - 1];
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