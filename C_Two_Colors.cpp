#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector <int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    // vector <int> store(n);
    i64 ans = 0;
    for (int i = 1; i < n; i++) {
        int j = lower_bound(a.begin(), a.end(), i) - a.begin();
        int k = lower_bound(a.begin(), a.end(), n - i) - a.begin();
        if (j < k && k != m) {
            ans += 1ll * 2 * (k - j) * (m - k);
        }
        if (k < m) {
            int l = max(j, k);
            ans += 1ll * (m - l) * (m - l - 1);
        }
        // store[i] = ans;
    }
    // for (int i : store) {
    //     cout << i << ' ';
    // }
    // cout << '\n';
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    return 0;
}