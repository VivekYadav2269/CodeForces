#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        vector <int> mn(n);
        mn[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            mn[i] = min(mn[i + 1], a[i]);
        }
        
        vector <bool> vis(n, false);
        int mx = 1e9 + 1;
        for (int i = 0; i < n; i++) {
            if (a[i] > mn[i]) {
                a[i]++;
                vis[i] = true;
                mx = min(mx, a[i]);
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (a[i] > mx && !vis[i]) {
                a[i]++;
            }
        }
        sort(a.begin(), a.end());
        
        for (int i = 0; i < n; i++) {
            cout << a[i] << " \n"[i == n - 1];
        }
    }

    return 0;
}