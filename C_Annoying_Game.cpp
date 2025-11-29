#include <bits/stdc++.h>
using i64 = long long;

const i64 inf = 1E18;

void solve() {
    int n, k;
    std::cin >> n >> k;
    
    std::vector <int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    
    std::vector <i64> f(n);
    i64 sum = 0, ans = -inf;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        ans = std::max(ans, sum);
        f[i] = sum;
        if (sum < 0) {
            sum = 0;
        }
    }
    
    if (k & 1) {
        i64 ff = 1LL * a[0] + abs(b[0]);
        i64 res = ff;
        for (int i= 1; i < n; i++) {
            ff = std::max(ff + a[i], f[i] + abs(b[i]));
            res = std::max(res, ff);
        }
        ans = res;
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
