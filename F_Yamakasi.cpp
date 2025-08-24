#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n, x;
    i64 s;
    std::cin >> n >> s >> x;
    
    std::vector <int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    auto cal = [&](int max) -> i64 {
        i64 ans = 0;
        for (int i = 0; i < n; i++) {
            i64 sum = 0;
            std::map <i64, int> m;
            m[0] = 1;
            int j = i;
            while (j < n && a[j] <= max) {
                sum += 1LL * a[j];
                ans += 1LL * m[sum - s];
                m[sum]++;
                j++;
            }
            i = j;
        }
        return ans;
    };
    std::cout << cal(x) - cal(x - 1) << '\n';
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