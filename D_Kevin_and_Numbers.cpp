#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    multiset <int> b;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        b.insert(x);
    }
    
    for (int i = n - 1; i >= 0;) {
        if (b.empty() || b.size() > i + 1) {
            cout << "No" << '\n';
            return;
        }
        
        int x = *b.rbegin();
        b.extract(x);
        
        if (a[i] > x) {
            cout << "No" << '\n';
            return;
        } else if (a[i] < x) {
            b.insert(x / 2);
            b.insert((x + 1) / 2);
        } else {
            i--;
        }
    }
    
    if (b.empty()) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
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