#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    
    std::vector <int> a(k);
    std::iota(a.begin(), a.end(), 1);
    std::vector ans(n, std::vector <int> (m));
    for (int i = 0; i < n; i++) {
        std::vector <int> na = a;
        for (int j = 0; j < m / k; j++) {
            for (int l = 0; l < k; l++) {
                ans[i][j * k + l] = a[l];
                na[l] = a[(l + 1) % k];
            }
        }
        a = na;
    }
    
    if (n % k != 0) {
        std::iota(a.begin(), a.end(), 1);
        for (int i = 0, l = 0; i < m % k; i++) {
            std::vector <int> na = a;
            for (int j = 0; j < n; j++) {
                ans[j][m / k * k + i] = a[l];
                l = (l + 1) % k;
            }
        }
    } else {
        std::iota(a.begin(), a.end(), 1);
        for (int i = 0; i < m % k; i++) {
            std::vector <int> na = a;
            for (int j = 0; j < n; j++) {
                ans[j][m / k * k + i] = a[j % k];
            }
            for (int j = 0; j < k; j++) {
                na[j] = a[(j + 1) % k];
            }
            a = na;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << ans[i][j] << " \n"[j == m - 1];
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