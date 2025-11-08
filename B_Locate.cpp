#include <bits/stdc++.h>
using i64 = long long;

int query(int x, int y) {
    std::cout << "? " << x << ' ' << y << std::endl;
    int res;
    std::cin >> res;
    return res;
}

void first() {
    int n;
    std::cin >> n;
    
    std::vector <int> p(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
    }
    
    int j = std::find(p.begin(), p.end(), n) - p.begin();
    int k = std::find(p.begin(), p.end(), 1) - p.begin();
    int x = j < k ? 0 : 1;
    std::cout << x << std::endl;
}

void second() {
    int n, x;
    std::cin >> n >> x;
    
    int l = 1, h = n;
    if (x == 0) {
        while (l < h) {
            int m = (l + h + 1) / 2;
            if (query(m, n) == n - 1) {
                l = m;
            } else {
                h = m - 1;
            }
        }
    } else {
        while (l < h) {
            int m = (l + h) / 2;
            if (query(1, m) == n - 1) {
                h = m;
            } else {
                l = m + 1;
            }
        }
    }
    std::cout << "! " << l << std::endl;
}
    
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string run;
    std::cin >> run;
    
    int t;
    std::cin >> t;
 
    while (t--) {
        if (run == "first") {
            first();
        } else {
            second();
        }
    }
    
    return 0;
}