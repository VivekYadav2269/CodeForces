#include <bits/stdc++.h>
using i64 = long long;

const int mod = 998244353;

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

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    
    int BAR = 1;
    std::vector seg(m + 1, std::vector <std::array <int, 2>> ());
    for (int i = 0; i < n; i++) {
        int l, r, p, q;
        std::cin >> l >> r >> p >> q;
        l--;
        int prob = mul(p, power(q, mod - 2));
        int bar = sub(1, prob);
        BAR = mul(BAR, bar);
        seg[r].push_back({l, mul(prob, power(bar, mod - 2))});
    }
    
    std::vector <int> dp(m + 1);
    dp[0] = 1;
    for (int i = 1; i <= m; i++) {
        for (auto a : seg[i]) {
            dp[i] = add(dp[i], mul(dp[a[0]], a[1]));
        }
    }
    
    dp[m] = mul(dp[m], BAR);
    std::cout << dp[m] << '\n';
    
    return 0;
}