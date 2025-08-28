#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using i64 = long long;

template <typename T>
using ordered_set = __gnu_pbds::tree <T, __gnu_pbds::null_type, std::less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

void solve() {
    int n;
    std::cin >> n;

    std::vector <std::array <int, 2>> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i][0] >> a[i][1];
    }
    std::sort(a.begin(), a.end());

    ordered_set <int> st;
    i64 ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        st.insert(a[i][1]);
        int j = st.order_of_key(a[i][1]);
        ans += j;
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