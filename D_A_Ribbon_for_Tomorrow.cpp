#include <bits/stdc++.h>
using i64 = long long;

const int mod = 998244353;
const int N = 1E6 + 7;

int Add(int x, int y) {
    x += y;
    if (x >= mod) {
        x -= mod;
    }
    return x;
}

int Sub(int x, int y) {
    x -= y;
    if (x < 0) {
        x += mod;
    }
    return x;
}

int Mul(int x, int y) {
    return 1LL * x * y % mod;
}

int Power(int x, int y) {
    int ans = 1;
    for (; y != 0; x = Mul(x, x), y >>= 1) {
        if (y & 1) {
            ans = Mul(ans, x);
        }
    }
    return ans;
}

std::vector <int> Fact(N), Inv(N), invFact(N);

void comb() {
    Fact[0] = 1, Inv[0] = 1, invFact[0] = 1;
    Fact[1] = 1, Inv[1] = 1, invFact[1] = 1;
    for (int i = 2; i < N; i++) {
        Inv[i] = Sub(0, Mul(Inv[mod % i], mod / i));
        Fact[i] = Mul(Fact[i - 1], i);
        invFact[i] = Mul(invFact[i - 1], Inv[i]);
    }
}

int C(int n, int r) {
    if (n < 0 || r < 0 || n < r) {
        return 0;
    }
    return Mul(Fact[n], Mul(invFact[n - r], invFact[r]));
}

void solve() {
    int n;
    std::cin >> n;
    
    std::string s;
    std::cin >> s;
    
    std::array <int, 2> cnt = {0, 0}, CNT = {0, 0};
    int c = 0;
    for (int i = 1; i < n; i++) {
        if (s[i - 1] == s[i]) {
            c++;
        } else {
            CNT[s[i - 1] - '0'] += c;
            cnt[s[i - 1] - '0']++;
            c = 0;
        }
    }
    
    CNT[s[n - 1] - '0'] += c;
    cnt[s[n - 1] - '0']++;
    
    int ans = 0;
    if (cnt[0] > 1) {
        ans = Add(ans, C(CNT[0] + cnt[0] - 1, cnt[0] - 1));
    }
    if (cnt[1] > 1) {
        if (ans == 0) {
            ans = 1;
        }
        int x = std::max(1, C(CNT[1] + cnt[1] - 1, cnt[1] - 1));
        ans = Mul(ans, x);
    }
    
    if (ans == 0) {
        ans = 1;
    }
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