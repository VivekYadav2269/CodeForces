#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;
    
    vector <int> x(n);
    map <int, i64> m;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        m[x[i]]++;
    }
    i64 sum = accumulate(x.begin(), x.end(), 0LL);
    
    i64 pre = 0, f = 0;
    for (auto &[x, y] : m) {
        i64 New = 1LL * f * x - pre + sum - pre - 1LL * x * y - 1LL * x * (n - f - y) + 1LL * n;
        pre += 1LL * x * y;
        f += y;
        y = New;
    }
    
    for (int i = 0; i < n; i++) {
        cout << m[x[i]] << " \n"[i == n - 1];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}