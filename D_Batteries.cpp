#include <bits/stdc++.h>
using i64 = long long;

int query(int u, int v) {
    std::cout << u + 1 << ' ' << v + 1 << std::endl;
    int res;
    std::cin >> res;
    return res;
}

void solve() {
    int n;
    std::cin >> n;
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (query(j, (j + i) % n)) {
                return;
            }
        }
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