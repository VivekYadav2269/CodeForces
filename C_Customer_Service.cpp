#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;
    
    vector a(n, vector <int> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n / 2; j++) {
            swap(a[i][j], a[i][n - 1 - j]);
        }
    }
    sort(a.begin(), a.end());
    
    int ans = 1;
    for (int i = n - 2, j = 0; i >= 0; i--) {
        if (a[i][j] == 1) {
            ans = ++j + 1;
        }
    }
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