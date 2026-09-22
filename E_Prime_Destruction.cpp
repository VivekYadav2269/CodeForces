#include <bits/stdc++.h>
using i64 = long long;

constexpr i64 inf = 1E18;

constexpr int N = 2E5;
std::vector <int> spf, primes;

void sieve() {
    spf.assign(N + 1, 0);
    primes.clear();

    for (int i = 2; i <= N; i++) {
        if (spf[i] == 0) {
            spf[i] = i;
            primes.push_back(i);
        }

        for (int j = 0; j < primes.size(); j++) {
            int p = primes[j];
            if (p > N / i || p > spf[i]) {
                break;
            }
            spf[i * p] = p;
        }
    }
}

void solve() {
    int n, k;
    std::cin >> n >> k;
    
    std::vector <int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::vector <i64> dp(n + 1, inf);
    for (int i = 1; i <= n; i++) {
        if (i <= k) {
            dp[i] = 0;
        } else {
            int j = i;
            while (j > 1) {
                dp[i] = std::min(dp[i], dp[i / spf[j]] * spf[j] + 1);
                j /= spf[j];
            }
        }
    }
    
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        ans += dp[a[i]];
    }
    std::cout << ans << '\n';
}
    
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    sieve();

    int t;
    std::cin >> t;
 
    while (t--) {
        solve();
    }
    
    return 0;
}