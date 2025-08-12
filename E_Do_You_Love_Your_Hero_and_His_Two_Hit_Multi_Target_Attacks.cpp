#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
vector <int> store;

void solve() {
    int k;
    cin >> k;
    
    vector <pair <int, int>> a;
    int n = 0;
    for (int i = 446; i >= 0; i--) {
        if (k - store[i] >= 0) {
            int sub = k / store[i];
            k -= sub * store[i];
            n += sub * (i + 2);
            a.push_back({sub, i + 2});
        }
    }
    
    // cout << "a size : " << a.size() << '\n';
    // for (int i = 0; i < a.size(); i++) {
    //     cout << a[i].first << ' ' << a[i].second << '\n';
    // }
    
    cout << n << '\n';
    for (int i = 0, x = 0, y = 0; i < a.size(); i++) {
        for (int j = 0; j < a[i].first; j++, x++) {
            for (int r = 0; r < a[i].second; r++, y++) {
                cout << x << ' ' << y << '\n';
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    store.push_back(1);
    int x = 1;
    while(store.back() <= 1e5) {
        x++;
        store.push_back(store.back() + x);
    }
    // for (int a : store) {
    //     cout << a << ' ';
    // }
    
    while (t--) {
        solve();
    }
    return 0;
}