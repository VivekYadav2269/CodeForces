#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        string a, b, c;
        cin >> a >> b >> c;
        
        int n = (int)a.size(), m = (int)b.size();
        vector dp(n + 1, vector <int> (m + 1, 1 << 30));
        dp[0][0] = 0;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i < n) {
                    dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + (a[i] != c[i + j]));
                }
                if (j < m) {
                    dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + (b[j] != c[i + j]));
                }
            }
        }
        
        cout << dp[n][m] << '\n';
    }

    return 0;
}