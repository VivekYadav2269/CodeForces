#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    
    std::vector <i64> a(n), b(m);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        std::cin >> b[i];
    }
    
    i64 g = 0;
    i64 min = *std::min_element(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        g = std::gcd(g, a[i] - min);
    }
    
    for (int i = 0; i < m; i++) {
        if (g == 0) {
            std::cout << min + b[i] << ' ';
            continue;
        }
        i64 d = b[i] % g;
        std::cout << std::gcd(g, min + d) << ' ';
    }
    std::cout << '\n';
    
    return 0;
}