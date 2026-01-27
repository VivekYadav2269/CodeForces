#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n, q;
    std::cin >> n >> q;
    
    n = 1 << n;
    
    std::vector <int> a(n), pre(n + 1);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        pre[i + 1] = pre[i] ^ a[i];
    }
    
    for (int i = 0; i < q; i++) {
        int b, c;
        std::cin >> b >> c;
        
        int l = 1, h = n, ans = 0;
        while (l < h) {
            int m = (l + h) / 2;
            int L = pre[m] ^ pre[l - 1], R = pre[h] ^ pre[m];
            bool ll = l <= b && b <= m;
            if (ll) {
                L ^= a[b - 1] ^ c;
            } else {
                R ^= a[b - 1] ^ c;
            }
            if (L < R) {
                if (ll) {
                    ans += h - m;
                }
            } else {
                if (!ll) {
                    ans += h - m;
                }
            }
            if (ll) {
                h = m;
            } else {
                l = m + 1;
            }
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