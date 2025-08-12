#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;
    
    vector <int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    i64 ans = 0;
    int mn = 2e9, mx = 0;
    for (int i = 0; i < n; i++) {
        ans += 1ll * abs(a[i] - b[i]);
        mx = max(mx, min(a[i], b[i]));
        mn = min(mn, max(a[i], b[i]));
    }
    ans += 2ll * max(mx - mn, 0);
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