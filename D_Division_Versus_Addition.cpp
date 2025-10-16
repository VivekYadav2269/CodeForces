#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n, q;
    std::cin >> n >> q;
    
    std::vector <int> pre(n + 1), inc(n + 1);
    for (int i = 0; i < n; i++) {
        i64 x;
        std::cin >> x;
        pre[i + 1] = pre[i] + (63 - __builtin_clzll(x));
        inc[i + 1] = inc[i];
        if (x & (x - 1)) {
            if ((x - 1) & (x - 2)) {
                pre[i + 1]++;
            } else {
                inc[i + 1]++;
            }
        }
    }
    
    for (int i = 0; i < q; i++) {
        int l, r;
        std::cin >> l >> r;
        l--;
        std::cout << pre[r] - pre[l] + (inc[r] - inc[l]) / 2 << '\n';
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