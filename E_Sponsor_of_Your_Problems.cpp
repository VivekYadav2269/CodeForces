#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    std::string l, r;
    std::cin >> l >> r;
    
    int n = l.size();
    bool cons = false;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if ((l[i] < r[i] && l[i] + 1 < r[i]) || (l[i] > r[i] && (r[i] + 9 > l[i]))) {
            std::cout << ans << '\n';
            return;
        } else if (cons && (l[i] == r[i] || (l[i] < r[i] && r[i] != '0') || (l[i] > r[i] && l[i] != '9'))) {
            std::cout << ans << '\n';
            return;
        } else {
            if (l[i] == r[i]) {
                ans += 2;
            } else {
                cons = true;
                ans++;
            }
        }
    }
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