#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 inf = 1e18;
vector dp(60, vector <i64> (60, inf));

void cal() {
    dp[0][0] = 0;
    for (int i = 0; i < 60; i++) {
        for (int x = 59; x >= 0; x--) {
            for (int y = 59; y >= 0; y--) {
                if (x + i < 60) {
                    dp[x + i][y] = min(dp[x + i][y], dp[x][y] + (1LL << i));
                }
                if (y + i < 60) {
                    dp[x][y + i] = min(dp[x][y + i], dp[x][y] + (1LL << i));
                }
            }
        }
    }
}

void solve() {
    i64 x, y;
    cin >> x >> y;
    
    i64 ans = inf;
    for (int i = 0; i < 60; i++) {
        for (int j = 0; j < 60; j++) {
            if (x >> i == y >> j) {
                ans = min(ans, dp[i][j]);
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cal();
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    return 0;
}