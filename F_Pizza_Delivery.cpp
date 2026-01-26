#include <bits/stdc++.h>
using i64 = long long;

const i64 inf = 1E18;

void solve() {
    int n, ax, ay, bx, by;
    std::cin >> n >> ax >> ay >> bx >> by;
    
    std::vector <int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> y[i];
    }
    
    std::map <int, std::vector <int>> mp;
    for (int i = 0; i < n; i++) {
        mp[x[i]].push_back(y[i]);
    }
    mp[bx].push_back(by);
    
    for (auto &[x, y] : mp) {
        std::sort(y.begin(), y.end());
    }
    
    int m = mp.size();
    std::vector <std::array <i64, 2>> dp(m + 1, {inf, inf});
    dp[0][0] = 0;
    dp[0][1] = 0;
    i64 ans = 0;
    int f = ay, l = ay, i = 1;
    for (auto [x, y] : mp) {
        bool first = true;
        int F, L;
        for (int Y : y) {
            if (first) {
                F = Y;
                first = false;
            }
            L = Y;
        }
        dp[i][0] = std::min(dp[i - 1][1] + abs(f - F), dp[i - 1][0] + abs(l - F));
        dp[i][1] = std::min(dp[i - 1][0] + abs(l - L), dp[i - 1][1] + abs(f - L));
        ans += L - F;
        f = F, l = L;
        i++;
    }
    
    ans += std::min(dp[m][0], dp[m][1]) + bx - ax;
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

