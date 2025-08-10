#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector <int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    
    if (a[n - 1] != b[n - 1]) {
        std::cout << "NO" << '\n';
        return;
    }
    
    for (int i = 1; i < n; i++) {
        if (a[i - 1] != b[i - 1]) {
            if (((a[i - 1] ^ a[i]) == b[i - 1]) || ((a[i - 1] ^ b[i]) == b[i - 1])) {
                // do nothing
            } else {
                std::cout << "NO" << '\n';
                return;
            }
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