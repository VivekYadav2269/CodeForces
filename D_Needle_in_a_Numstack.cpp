#include <bits/stdc++.h>
using i64 = long long;

int query(int x) {
    std::cout << "? " << x + 1 << std::endl;
    int res;
    std::cin >> res;
    return res;
}

void solve() {
    int n, k;
    std::cin >> n >> k;
    
    if (k + k == n) {
        std::cout << "! " << k << ' ' << k << std::endl;
        return;
    }
    
    std::vector <int> a(k), b(k);
    for (int i = 0; i < k; i++) {
        int x = query(i);
        int y = query(n - k + i);
        a[i] = x;
        b[i] = y;
    }
    
    int x = -1, y = n / k * k;
    if (y == n) {
        y -= k;
    }
    int j = (k - n % k) % k;
    for (int i = 0; i < k; i++, j = (j + 1) % k) {
        if (y >= n) {
            y -= k;
        }
        if (a[i] != b[j]) {
            x = i;
            break;
        }
        y++;
    }
    
    if (x == -1) {
        std::cout << "! " << -1 << std::endl;
        return;
    }

    int l = x, r = y;
    while (l < r) {
        int diff = (r - l) / k;
        int m = l + (diff + 1) / 2 * k;
        if (query(m) == a[x]) {
            l = m;
        } else {
            r = m - k;
        }
    }

    int A = l + 1;
    bool done = false;
    std::vector <int> check;
    for (int i = l + 1; i < n - 1 && i < l + 2 * k; i++) {
        int p = query(i);
        if (p == a[i % k] && i < n - k && !done) {
            A++;
        } else {
            done = true;
        }
        if (A > k) {
            check.push_back(p);
        }
    }
    
    int B = std::min(n - 1, l + 2 * k);
    if (!check.empty()) {
        int idx = std::find(b.begin(), b.end(), check.back()) - b.begin();
        for (int i = check.size() - 1; i >= 0; i--, B--, idx = (idx - 1 + k) % k) {
            if (check[i] != b[idx]) {
                break;
            }
        }
    }
    if (A > B) {
        std::cout << "! " << -1 << std::endl;
        return;
    }
    std::cout << "! " << A << ' ' << n - A << std::endl;
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