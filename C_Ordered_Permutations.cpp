#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n;
    i64 k;
    cin >> n >> k;
    
    if (n <= 60 && k > (1LL << (n - 1))) {
        cout << -1 << '\n';
        return;
    }
    
    vector <int> p(n);
    int l = 0, r = n - 1;
    for (int i = 1; i < n; i++) {
        if (n - 1 - i > 60 || k <= (1LL << (n - 1 - i))) {
            p[l++] = i;
        } else {
            p[r--] = i;
            k -= (1LL << (n - 1 - i));
        }
    }
    p[l] = n;
    
    for (int i = 0; i < n; i++) {
        cout << p[i] << " \n"[i == n - 1];
    }
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