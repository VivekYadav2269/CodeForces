#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector <int> p(n);
    std::set <int> s;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        x--;
        p[x] = i;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        s.insert(p[i]);
        int x = std::distance(s.begin(), s.lower_bound(p[i]));
        ans += std::min(p[i] - x, n - p[i] + x - (int)s.size());
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