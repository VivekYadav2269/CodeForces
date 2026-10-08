#include <bits/stdc++.h>
using i64 = long long;

constexpr i64 inf = 1LL << 61;

void solve() {
    int n;
    std::cin >> n;
    
    i64 k;
    std::cin >> k;
    
    std::vector <int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i] >> b[i] >> c[i];
    }
    
    auto check = [&](i64 x) -> bool {
        i64 K = 0;
        for (int i = 0; i < n; i++) {
            i64 p = 1LL * a[i] + b[i] + c[i];
            if (p >= x) {
                continue;
            }
            if (a[i] == b[i] && b[i] == c[i]) {
                return false;
            }
            K += x - p + 2 * std::max(0, std::min(b[i] - a[i], c[i] - b[i]) + 1);
            if (K > k) {
                return false;
            }
        }
        return true;
    };
    
    i64 l = -inf, h = inf;
    while (l < h) {
        i64 m = (l + h + 1) / 2;
        if (check(m)) {
            l = m;
        } else {
            h = m - 1;
        }
    }
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