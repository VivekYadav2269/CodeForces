#include <bits/stdc++.h>
using i64 = long long;

const int mod = 998244353;
const int N = 5E5 + 1;

int add(int x, int y) {
    x += y;
    if (x >= mod) {
        x -= mod;
    }
    return x;
}

int sub(int x, int y) {
    x -= y;
    if (x < 0) {
        x += mod;
    }
    return x;
}

int mul(int x, int y) {
    return 1LL * x * y % mod;
}

int power(int x, int y) {
    int ans = 1;
    for (; y != 0; x = mul(x, x), y >>= 1) {
        if (y & 1) {
            ans = mul(ans, x);
        }
    }
    return ans;
}

std::vector <int> fact(N), inv(N), invFact(N);

void comb() {
    fact[0] = 1, inv[0] = 1, invFact[0] = 1;
    fact[1] = 1, inv[1] = 1, invFact[1] = 1;
    for (int i = 2; i < N; i++) {
        inv[i] = sub(0, mul(inv[mod % i], mod / i));
        fact[i] = mul(fact[i - 1], i);
        invFact[i] = mul(invFact[i - 1], inv[i]);
    }
}

void solve() {
    std::array <int, 26> c;
    for (int i = 0; i < 26; i++) {
        std::cin >> c[i];
    }
    
    int n = std::accumulate(c.begin(), c.end(), 0);
    std::vector <int> dp(n / 2 + 1);
    dp[0] = 1;
    for (int i = 0; i < 26; i++) {
        if (c[i] == 0) {
            continue;
        }
        std::vector <int> ndp = dp;
        for (int j = n / 2; j >= c[i]; j--) {
            ndp[j] = add(ndp[j], dp[j - c[i]]);
        }
        std::swap(dp, ndp);
    }
    
    int inv = 1;
    for (int i = 0; i < 26; i++) {
        inv = mul(inv, invFact[c[i]]);
    }
    
    int ans = mul(mul(fact[n / 2], fact[(n + 1) / 2]), mul(inv, dp[n / 2]));
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    comb();
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}