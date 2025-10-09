#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    i64 l, r;
    std::cin >> l >> r;
    
    std::set <i64> st;
    for (int i = l; i <= r; i++) {
        st.insert(i);
    }

    if (r == 0) {
        std::cout << 0 << '\n';
        std::cout << 0 << '\n';
        return;
    }
    
    int msb = 64 - __builtin_clzll(r);
    i64 ans = 0;
    std::vector <int> a(r - l + 1, -1);
    for (int i = msb; !st.empty() && i >= 0; i--) {
        i64 mask = (1LL << i) - 1;
        for (int j = l; j <= r; j++) {
            if (st.contains(j) && st.contains(mask ^ j) && j != (mask ^ j)) {
                ans += j | mask;
                ans += (j ^ mask) | mask;
                st.erase(j);
                st.erase(j ^ mask);
                a[j - l] = j ^ mask;
                a[(j ^ mask) - l] = j;
            }
        }
    }
    i64 x;
    if (!st.empty()) {
        x = *st.begin();
        ans += x;
    }
    
    std::cout << ans << '\n';
    for (int i = 0; i < r - l + 1; i++) {
        if (a[i] == -1) {
            std::cout << x << ' ';
        } else {
            std::cout << a[i] << ' ';
        }
    }
    std::cout << '\n';
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