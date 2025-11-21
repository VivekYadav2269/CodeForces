#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector <int> a(n), at(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i]--;
        at[a[i]] = i;
    }
    
    std::vector <int> min(n), max(n);
    max[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        max[i] = std::max(max[i + 1], a[i]);
    }
    min[0] = a[0];
    for (int i = 1; i < n; i++) {
        min[i] = std::min(min[i - 1], a[i]);
    }
    
    int mx = 0;
    for (int i = 0; i < n; i++) {
        if (i > mx) {
            std::cout << "NO"  << '\n';
            return;
        }
        mx = std::max(mx, max[at[i]]);
        
    }
    
    std::cout << "YES" << '\n';
    std::set <std::array <int, 2>> st;
    int sz = 0;
    std::vector <int> check;
    for (int i = 0; i < n - 1; i++) {
        if (at[i] + 1 < n && i < max[at[i] + 1]) {
            std::cout << i + 1 << ' ' << max[at[i] + 1] + 1 << '\n';
            st.insert({i + 1, max[at[i] + 1] + 1});
            sz++;
        } else if (at[i] - 1 >= 0 && min[at[i] - 1] < i && !st.contains({min[at[i] - 1] + 1, i + 1})) {
            std::cout << i + 1 << ' ' << min[at[i] - 1] + 1 << '\n';
            st.insert({i + 1, min[at[i] - 1] + 1});
            sz++;
        } else {
            check.push_back(i);
        }
    }
    
    if (sz < n - 1) {
        for (int x : check) {
            for (int i = at[x] - 1; i >= 0; i--) {
                if (a[i] < x && !st.contains({a[i] + 1, x + 1}) && !st.contains({x + 1, a[i] + 1})) {
                    std::cout << x + 1 << ' ' << a[i] + 1 << '\n';
                    st.insert({x + 1, a[i] + 1});
                    break;
                }
            }
        }
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