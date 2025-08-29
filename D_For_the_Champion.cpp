#include <bits/stdc++.h>
using i64 = long long;

const int k = int(1E9);

i64 query(char Dir, int dis) {
    std::cout << "? " << Dir << ' ' << dis << std::endl;
    i64 res;
    std::cin >> res;
    return res;
}

void solve() {
    int n;
    std::cin >> n;
    
    std::vector <int> x(n), y(n);
    int add = 1LL * (-2E9), sub = 1LL * (-2E9);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i] >> y[i];
        add = std::max(add, x[i] + y[i]);
        sub = std::max(sub, x[i] - y[i]);
    }
    
    query('U', k);
    query('U', k);
    query('R', k);
    i64 A = query('R', k);
    query('D', k);
    query('D', k);
    query('D', k);
    i64 B = query('D', k);
    
    int X = (A + B + add + sub - 1LL * 8 * k) / 2;
    int Y = (A - B + add - sub) / 2;
    std::cout << "! " << X << ' ' << Y << std::endl;
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