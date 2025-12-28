#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector <int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    if (m > n / 2) {
        std::cout << "-1\n";
        return;
    }
    
    std::vector <int> ord(n);
    std::iota(ord.begin(), ord.end(), 0);
    std::sort(ord.begin(), ord.end(), [&](int i, int j) {
        return a[i] < a[j];
    });
    std::vector <std::array <int, 2>> ans;
    if (m == 0) {
        i64 sum = std::accumulate(a.begin(), a.end(), 0LL);
        if (2 * a[ord[n - 1]] > sum) {
            std::cout << "-1\n";
            return;
        }
        int x = 0;
        while (x < n - 1 && a[ord[n - 1]] > a[ord[n - 2]]) {
            ans.push_back({ord[x], ord[n - 1]});
            a[ord[n - 1]] -= a[ord[x]];
            x++;
        }
        for (int i = x; i < n - 1; i++) {
            ans.push_back({ord[i], ord[i + 1]});
        }
    } else {
        for (int i = 0; i < n - 2 * m; i++) {
            ans.push_back({ord[i], ord[i + 1]});
        }
        for (int i = 0; i < m; i++) {
            ans.push_back({ord[n - 1 - i], ord[n - 1 - m - i]});
        }
    }
    
    std::cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i][0] + 1 << ' ' << ans[i][1] + 1 << '\n';
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