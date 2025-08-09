#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    
    std::vector <int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
        if (a[i] > b[i]) {
            std::swap(a[i], b[i]);
        }
        ans += 1LL * (b[i] - a[i]);
    }
    
    std::vector <int> at(n);
    std::iota(at.begin(), at.end(), 0);
    std::sort(at.begin(), at.end(), [&](int i, int j) {
        if (a[i] == a[j]) {
            return b[i] < b[j];
        }
        return a[i] < a[j];
    });
    
    i64 nans = 1E15;
    for (int i = 1; i < n; i++) {
        int x = at[i - 1], y = at[i];
        int first = b[x] - a[x];
        int second = b[y] - a[y];
        nans = std::min(nans, ans + 1LL * (b[y] - a[x] + abs(a[y] - b[x]) - first - second));
    }
    std::cout << nans << '\n';
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