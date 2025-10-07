#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::string s;
    std::cin >> s;
    
    std::vector <int> suf(n + 1);
    int a = 0;
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = suf[i + 1];
        suf[i] += (s[i] == 'a') ? 1 : -1;
        a += s[i] == 'a' ? 1 : -1;
    }
    
    if (a == 0) {
        std::cout << 0 << '\n';
        return;
    }
    
    int ans = n;
    std::map <int, int> m;
    for (int i = 0; i < n; i++) {
        m[suf[i] - a] = i;
        if (m.contains(suf[i + 1])) {
            ans = std::min(ans, i + 1 - m[suf[i + 1]]);
        }
    }
    if (ans == n) {
        std::cout << -1 << '\n';
    } else {
        std::cout << ans << '\n';
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