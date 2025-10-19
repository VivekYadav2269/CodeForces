#include <bits/stdc++.h>
using i64 = long long;

int p(int l, int r) {
    std::cout << "1 " << l << ' ' << r << std::endl;
    int res;
    std::cin >> res;
    return res;
}

int a(int l, int r) {
    std::cout << "2 " << l << ' ' << r << std::endl;
    int res;
    std::cin >> res;
    return res;
}

void solve() {
    int n;
    std::cin >> n;
    
    int l = 1, r = n;
    int d = a(l, r) - p(l, r);
    while (l < r) {
        int m = (l + r + 1) / 2;
        int check = a(m, r) - p(m, r);
        if (check == d) {
            l = m;
        } else if (check == 0) {
            r = m - 1;
        } else {
            l = m - d + check;
            r = l + d - 1;
            break;
        }
    }
    std::cout << "! " << l << ' ' << r << std::endl;
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