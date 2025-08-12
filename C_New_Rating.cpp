#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        
        vector <int> a(n);
        for (int &i : a) {
            cin >> i;
        }
        
        int dp0 = 0, dp1 = -N, dp2 = -N;
        for (int i = 0; i < n; i++) {
            dp2 = max(dp2, dp1);
            dp1 = max(dp1, dp0);
            dp0 += a[i] >= dp0 ? a[i] > dp0 : -1;
            dp2 += a[i] >= dp2 ? a[i] > dp2 : -1;
        }
        
        int ans = max(dp1, dp2);
        cout << ans << '\n';
    }

    return 0;
}