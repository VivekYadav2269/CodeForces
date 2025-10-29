#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n, k, x;
    std::cin >> n >> k >> x;
    
    std::vector <int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    
    auto check = [&](int d) -> bool {
        int K = k;
        K -= std::max(0, a[0] - d + 1);
        K -= std::max(0, x - a[n - 1] - d + 1);
        for (int i = 0; i < n - 1; i++) {
            int DD = a[i] + d;
            K -= std::max(0, a[i + 1] - d - a[i] - d + 1);
        }
        return K <= 0;
    };
    
    int l = 0, r = x;
    while (l < r) {
        int m = (l + r + 1) / 2;
        if (check(m)) {
            l = m;
        } else {
            r = m - 1;
        }
    }

    if (l == 0) {
        std::cout << a[0] << ' ';
        for (int i = 1, j = 0; i < k; i++, j++) {
            if (j == a[0]) {
                j++;
            }
            std::cout << j << ' ';
        }
        std::cout << '\n';
        return;
    }
    
    int DD = a[0] - l;
    while (DD >= 0 && k) {
        std::cout << DD << ' ';
        DD--;
        k--;
    }
    DD = a[n - 1] + l;
    while (DD <= x && k) {
        std::cout << DD << ' ';
        DD++;
        k--;
    }
    for (int i = 0; i < n - 1; i++) {
        int DD = a[i] + l;
        while (DD <= a[i + 1] - l && k) {
            std::cout << DD << ' ';
            DD++;
            k--;
        }
    }
    std::cout << '\n';
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