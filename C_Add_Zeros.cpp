#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<pair <i64, i64>> a;
        for (int i = 0; i < n; i++) {
            i64 x;
            cin >> x;

            if (x + i >= n && i > 0) {
                a.push_back({x + i, x + i + i});
            }
        }
        sort(a.begin(), a.end(), std::greater());
        
        map<i64, i64> dp;
        dp[n] = n;
        for (auto [x, y] : a) {
            if (!dp.contains(x)) {
                dp[x] = x;
            }
            dp[x] = max(dp[x], dp.contains(y) ? dp[y] : y);
        }
        
        cout << dp[n] << "\n";
    }
    
    return 0;
}