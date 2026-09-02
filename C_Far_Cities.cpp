#include <bits/stdc++.h>
using i64 = long long;

int query(int x, int y, int D) {
    std::cout << "? " << x << ' ' << y << ' ' << D << std::endl;
    int res;
    std::cin >> res;
    
    return res;
}

void solve() {
    int n;
    std::cin >> n;
    
    int u = 1, U = 1, d = 1;
    for (int i = 2; i <= n; i++) {
        int j = i;
        while (d < n && query(u, i, d)) {
            d++;
            U = i;
        }
    }
    d--;
    
    u = U;
    int v = u;
    for (int i = 1; i <= n; i++) {
        if (i == u) {
            continue;
        }
        while (d < n && query(u, i, d)) {
            d++;
            v = i;
        }
    }
    d--;
    std::cout << "! " << u << ' ' << v << ' ' << d << std::endl;
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