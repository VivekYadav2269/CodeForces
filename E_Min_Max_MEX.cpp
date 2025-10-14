#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    
    std::vector <int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    auto check = [&](int m) -> bool {
        int mex = 0, sub = 0;
        std::vector <bool> vis(m);
        for (int i = 0; i < n; i++) {
            if (a[i] < m && !vis[a[i]]) {
                vis[a[i]] = true;
                mex++;
            }
            if (mex == m) {
                mex = 0;
                for (int i = 0; i < m; i++) {
                    vis[i] = false;
                }
                sub++;
            }
        }
        return sub >= k;
    };
    
    int l = 0, r = n + 1;
    while (l < r) {
        int m = (l + r) / 2;
        if (check(m)) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    l -= l > 0;
    std::cout << l << '\n';
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