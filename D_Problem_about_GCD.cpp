#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    i64 l, r, g;
    cin >> l >> r >> g;
    
    i64 first = (l + g - 1) / g, second = r / g;
    i64 x = -1, y = -1; 
    for (i64 i = first; i <= second; i++) {
        for (i64 j = second; j >= i; j--) {
            if (__gcd(i, j) == 1) {
                if (x == -1 || y - x < j - i) {
                    x = i, y = j;
                }
                if (j == second) {
                    cout << x * g << ' ' << y * g << '\n';
                    return;
                }
                break;
            }
        }
    }
    if (x == -1) {
        cout << x << ' ' << y << '\n';
    } else {
        cout << x * g << ' ' << y * g << '\n';
    }
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}