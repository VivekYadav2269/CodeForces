#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int ask(int k) {
    cout << "? 1 " << k << endl;
    int res;
    cin >> res;
    return res;
}

void solve() {
    int l = 2, r = 999;
    while (l < r) {
        int mid = (l + r) / 2;
        if (ask(mid) <= 1 * mid) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    cout << "! " << l << endl;
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