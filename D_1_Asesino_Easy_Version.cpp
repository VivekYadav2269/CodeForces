#include <bits/stdc++.h>
using i64 = long long;

int query(int x, int y) {
    std::cout << "? " << x << ' ' << y << std::endl;
    int res;
    std::cin >> res;
    return res;
}

void solve() {
    int n;
    std::cin >> n;
    
    for (int i = 2; i <= n; i += 2) {
        int res = query(i - 1, i) ^ query(i, i - 1);
        if (res) {
            int j = i + 1 <= n ? i + 1 : i - 2;
            if (query(i - 1, j) ^ query(j, i - 1)) {
                std::cout << "! " << i - 1 << std::endl;
            } else {
                std::cout << "! " << i << std::endl;
            }
            return;
        }
    }    
    
    if (query(n - 1, n - 2) ^ query(n - 2, n - 1)) {
        std::cout << "! " << n - 1 << std::endl;
    } else {
        std::cout << "! " << n << std::endl;
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