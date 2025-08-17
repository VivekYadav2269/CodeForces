#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    
    std::vector <int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    if (k == 1) {
        std::cout << "YES" << '\n';
        return;
    }
    
    std::vector <int> b = a;
    std::sort(b.begin(), b.end());
    int x = std::count(b.begin(), b.begin() + k - 1, b[k - 2]);
    int y = std::count(b.begin(), b.end(), b[k - 2]);
    int K = k - 1;
    for (int i = 0, j = n - 1; K > 0 && i < j; ) {
        if (a[i] == a[j]) {
            if (a[i] == b[k - 2]) {
                K -= 2;
                x -= 2;
                y -= 2;
            } else if (a[i] < b[k - 2]) {
                K -= 2;
            }
            i++, j--;
        } else {
            if (a[i] < b[k - 2]) {
                if (a[j] > b[k - 2]) {
                    j--;
                } else if (a[j] == b[k - 2]) {
                    if (y > x) {
                        y--, j--;
                    } else {
                        std::cout << "NO" << '\n';
                        return;
                    }
                } else {
                    std::cout << "NO" << '\n';
                    return;
                }
            } else if (a[j] < b[k - 2]) {
                if (a[i] > b[k - 2]) {
                    i++;
                } else if (a[i] == b[k - 2]) {
                    if (y > x) {
                        y--, i++;
                    } else {
                        std::cout << "NO" << '\n';
                        return;
                    }
                } else {
                    std::cout << "NO" << '\n';
                    return;
                }
            } else if (a[i] > b[k - 2] && a[j] > b[k - 2]) {
                i++, j--;
            } else if (a[i] == b[k - 2]) {
                if (a[j] > b[k - 2]) {
                    j--;
                } else {
                    if (y > x) {
                        y--, i++;
                    } else {
                        std::cout << "NO" << '\n';
                        return;
                    }
                    
                }
            } else if (a[j] == b[k - 2]) {
                if (a[i] > b[k - 2]) {
                    i++;
                } else {
                    if (y > x) {
                        y--, j--;
                    } else {
                        std::cout << "NO" << '\n';
                        return;
                    }
                }
            }
        }
    }
    if (K > 1) {
        std::cout << "NO" << '\n';
        return;
    }
    std::cout << "YES" << '\n';
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