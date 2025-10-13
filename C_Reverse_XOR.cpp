#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    if (n == 0) {
        std::cout << "YES" << '\n';
        return;
    }
    
    int l = 31 - __builtin_clz(n), r = __builtin_ctz(n);
    for (; l > r; l--, r++) {
        if ((n >> l & 1) != (n >> r & 1)) {
            std::cout << "NO" << '\n';
            return;
        }
    }
    
    if (l == r && n >> l & 1) {
        std::cout << "NO" << '\n';
        return;
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