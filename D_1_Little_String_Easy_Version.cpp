#include <bits/stdc++.h>
using i64 = long long;

const int mod = 1E9 + 7;

int Mul(int x, int y) {
    return 1LL * x * y % mod;
}

void solve() {
    int n, c;
    std::cin >> n >> c;
    
    std::string s;
    std::cin >> s;
    
    if (s[0] == '0' || s[n - 1] == '0') {
        std::cout << "-1\n";
        return;
    }
    
    int ans = 2, C = 2;
    for (int i = 1; i < n - 1; i++) {
        if (s[i] == '1') {
            ans = Mul(ans, 2);
            C = 1LL * C * 2 % c;
        } else {
            ans = Mul(ans, i);
            C = 1LL * C * i % c;
        }
    }
    
    if (C == 0) {
        std::cout << "-1\n";
        return;
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