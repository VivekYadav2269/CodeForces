#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n, q;
    std::cin >> n >> q;
    
    std::vector <int> a(n);
    std::multiset <int> ms;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        ms.insert(a[i]);
    }
    
    for (int i = 0; i < q; i++) {
        int c;
        std::cin >> c;
        
        std::vector <int> v, Added;
        int ans = 0;
        for (int j = 29; j >= 0; j--) {
            if (c >> j & 1) {
                auto lst = std::prev(ms.end());
                if (*lst < (1 << j)) {
                    ans += (1 << j) - *lst;
                    ms.insert(0);
                    Added.push_back(0);
                } else {
                    ms.insert(*lst - (1 << j));
                    Added.push_back(*lst - (1 << j));
                }
                ms.erase(lst);
                v.push_back(*lst);
            }
        }
        for (int x : v) {
            ms.insert(x);
        }
        for (int x : Added) {
            ms.extract(x);
        }
        std::cout << ans << '\n';
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