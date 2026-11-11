#include <bits/stdc++.h>
using i64 = long long;

constexpr i64 inf = 1E15;

void solve() {
    int n, l;
    std::cin >> n >> l;
    
    std::vector <int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::ranges::sort(a);
    
    std::vector <i64> pre(n - 1);
    pre[0] = a[0];
    for (int i = 1; i < n - 1; i++) {
        pre[i] = pre[i - 1] + a[i];
    }
    
    i64 ans = inf;
    for (int i = 0; i <= a[n - 2] && 1LL * i * i < l; i++) {
        i64 x = 0;
        int idx = std::upper_bound(a.begin(), a.end() - 1, i) - a.begin();
        if (idx != n - 1) {
            x = pre[n - 2] - 1LL * (n - 1 - idx) * i;
            if (idx) {
                x -= pre[idx - 1];
            } 
        }
        
        if (i) {
            x += std::max(0, a[n - 1] - (l - 1) / i);
        }
        ans = std::min(ans, x);
    }
    std::cout << ans << '\n';
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