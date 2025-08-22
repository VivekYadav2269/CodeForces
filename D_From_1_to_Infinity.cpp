#include <bits/stdc++.h>
using i64 = long long;
using i128 = __int128_t;

void solve() {
    i64 k;
    std::cin >> k;
    
    i64 ans = 0, res = 1, prev = 0, x = 1;
    while (k >= 9 * res * x) {
        k -= 9 * res * x;
        ans += 45 * res + 9 * prev;
        prev = ans;
        res *= 10;
        x++;
    }
    
    auto cal = [](i64 n) -> i64 {
        if (n < 0) {
            return 0LL;
        }
        i64 p = 1;
        i64 res = 0;
        while (p <= n) {
            i64 l = n / (p * 10);
            i64 a  = (n / p) % 10;
            i64 r  = n % p;

            i128 add = 0;
            add += (i128)l * 45 * p;
            add += (i128)a * (r + 1);
            add += (i128)(a * (a - 1) / 2) * p;
            res += (i64)add;

            if (p > (i64)1e18 / 10) {
                break;
            } 
            p *= 10;
        }
        return res;
    };
    
    if (k) {
        i64 r = k % x;
        k /= x;
        res = res - 1 + k;
        i64 RES = res, p = 1, z = 0;
        prev = 0;
        if (k) {
            ans += cal(res) - cal(res - k);
        }
        if (r) {
            res += 1LL;
            std::string R = std::to_string(res);
            for (int i = 0; i < r; i++) {
                ans += 1LL * (R[i] - '0');
            }
        }
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