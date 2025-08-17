#include <bits/stdc++.h>
using i64 = long long;

const int mod = 1E9 + 7;
const int N = 1E6 + 7;

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


void solve() {
    int n;
    std::cin >> n;
    
    std::vector <int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::stack <std::array <int, 2>> stk;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int y = 0;
        while (!stk.empty() && stk.top()[0] <= 1LL * power(2, y) * a[i]) {
            y = add(y, stk.top()[1]);
            ans = sub(ans, mul(power(2, stk.top()[1]), stk.top()[0]));
            ans = add(ans, stk.top()[0]);
            stk.pop();
        }
        ans = add(ans, mul(power(2, y), a[i]));
        std::cout << ans << " \n"[i == n - 1];
        while (a[i] % 2 == 0) {
            a[i] /= 2;
            y = add(y, 1);
        }
        stk.push({a[i], y});
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