#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main(){
    int t;
    cin >> t;
    
    while (t--) {
        i64 n, sum = 0;
        cin >> n;
        
        vector <i64> a(n);
        i64 mx = LLONG_MIN, mn = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
            
            mn = min(mn, sum / (i + 1));
        }
        
        sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            sum += a[i];
            
            mx = max(mx, (sum + n - i - 1) / (n - i));
        }
        
        cout << mx - mn << "\n";
    }
    return 0;
}