#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;

    if (k & 1) {
        for (int i = 0; i < k; i++) {
            std::cout << n << " \n"[i == k - 1];
        }
        return;
    }
    
    std::vector <int> ans(k);
    for (int i = 29, j = 0; i >= 0; i--) {
        if (n >> i & 1) {
            for (int l = j; l < j + k - 1; l++) {
                ans[l % k] |= 1 << i;
            }
            j = (j + 1) % k;
        }
    } 
    for (int i = 29; i >= 0; i--) {
        std::vector <int> v;
        for (int j = 0; j < k; j++) {
            if (!(ans[j] >> i & 1) && (ans[j] + (1 << i) <= n)) {
                v.push_back(j);
            }
        }
        if (v.size() & 1) {
            v.pop_back();
        }
        for (int j = 0; j < v.size(); j++) {
            ans[v[j]] |= 1 << i;
        }
    }
    
    for (int i = 0; i < k; i++) {
        std::cout << ans[i] << " \n"[i == k - 1];
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