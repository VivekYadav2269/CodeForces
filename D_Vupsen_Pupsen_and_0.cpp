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
        
        vector <int> ans(n, 1);
        if (n & 1) {
            int x = a[0] + a[1];
            if (x == 0) {
                x = a[0] + a[0] + a[1];
                ans[0] *= 2;
            }
            
            if (x > 0 && a[2] > 0) {
                ans[0] *= -a[2];
                ans[1] *= -a[2];
                ans[2] *= x;
            } else if (x < 0 && a[2] < 0) {
                ans[0] *= a[2];
                ans[1] *= a[2];
                ans[2] *= -x;
            } else {
                ans[0] *= a[2] > 0 ? a[2] : -a[2];
                ans[1] *= a[2] > 0 ? a[2] : -a[2];
                ans[2] *= x > 0 ? x : -x;
            }
            
            for (int i = 4; i < n; i += 2) {
                if (a[i - 1] > 0 && a[i] > 0) {
                    ans[i - 1] *= -a[i];
                    ans[i] *= a[i - 1];
                } else if (a[i - 1] < 0 && a[i] < 0) {
                    ans[i - 1] *= a[i];
                    ans[i] *= -a[i - 1];
                } else {
                    ans[i - 1] *= a[i] > 0 ? a[i] : -a[i];
                    ans[i] *= a[i - 1] > 0 ? a[i - 1] : -a[i - 1];
                }
            }
        } else {
            for (int i = 1; i < n; i += 2) {
                if (a[i - 1] > 0 && a[i] > 0) {
                    ans[i - 1] *= -a[i];
                    ans[i] *= a[i - 1];
                } else if (a[i - 1] < 0 && a[i] < 0) {
                    ans[i - 1] *= a[i];
                    ans[i] *= -a[i - 1];
                } else {
                    ans[i - 1] *= a[i] > 0 ? a[i] : -a[i];
                    ans[i] *= a[i - 1] > 0 ? a[i - 1] : -a[i - 1];
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " \n"[i == n - 1];
        }
    }

    return 0;
}