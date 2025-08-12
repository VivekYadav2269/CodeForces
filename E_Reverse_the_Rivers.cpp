#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
//     int t;
//     cin >> t;

//     while (t--) {
        int n, k, q;
        cin >> n >> k >> q;
        
        vector <vector <int>> a(k, vector <int> (n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                cin >> a[j][i];
            }
        }
        
        for (int i = 0; i < k; i++) {
            for (int j = 1; j < n; j++) {
                a[i][j] |= a[i][j - 1];
            }
        }
        
        while (q--) {
            int m;
            cin >> m;
            
            int mn = 0, mx = n - 1;
            while (m--) {
                int i, j;
                char o;
                cin >> i >> o >> j;
                i--;
                
                if (o == '>') {
                    int x = upper_bound(a[i].begin(), a[i].end(), j) - a[i].begin();
                    mn = max(mn, x);
                } else {
                    int x = lower_bound(a[i].begin(), a[i].end(), j) - a[i].begin();
                    mx = min(mx, x - 1);
                }
            }
            
            if (mn <= mx) {
                cout << mn + 1 << '\n';
            } else {
                cout << -1 << '\n';
            }
        }
    // }

    return 0;
}