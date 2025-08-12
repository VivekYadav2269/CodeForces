#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        vector dp(n + 1, vector <i64> (k + 1, 1ll << 60));
        dp[0][0] = 0;
        for (int i = 0; i < n; i++) {
            int mn = a[i];
            for (int j = 0; j <= k && i + j < n; j++) {
                mn = min(mn, a[i + j]);
                for (int x = 0; x + j <= k; x++) {
                    dp[i + j + 1][x + j] = min(dp[i + j + 1][x + j], dp[i][x] + 1ll * mn * (j + 1));
                }
            }
        }
        
        i64 ans = *min_element(dp[n].begin(), dp[n].end());
        cout << ans << '\n';
    }
    
    return 0;
}