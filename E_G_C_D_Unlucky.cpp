#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<i64> p(n), s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }
    
    std::vector <i64> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = std::lcm(p[i], s[i]);
    }

    i64 g = 0;
    for (int i = 0; i < n; i++) {
        g = std::gcd(g, a[i]);
        if (g != p[i]) {
            std::cout << "NO" << '\n';
            return;
        }
    }
    g = 0;
    for (int i = n - 1; i >= 0; i--) {
        g = std::gcd(g, a[i]);
        if (g != s[i]) {
            std::cout << "NO" << '\n';
            return;
        }
    }
    std::cout << "YES" << '\n';
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