#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    
    std::string s;
    std::cin >> s;
    
    std::vector <int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    auto check = [&](int x) -> bool {
        int cnt = k;
        int b = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > x) {
                if (cnt == k) {
                    if (s[i] == 'B') {
                        cnt--;
                        b = 1;
                    }
                } else if (b && s[i] == 'R') {
                    b = 0;
                } else if (!b && s[i] == 'B') {
                    b = 1;
                    cnt--;
                }
            }
        }
        return cnt >= 0;
    };
    
    int l = 0, h = 1 << 30;
    while (l < h) {
        int m = (l + h) / 2;
        if (!check(m)) {
            l = m + 1;
        } else {
            h = m;
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