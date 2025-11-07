#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    
    std::string s, t;
    std::cin >> s >> t;
    
    std::vector p(26, std::vector <int> ());
    for (int i = 0; i < n; i++) {
        p[s[i] - 'a'].push_back(i);
    }
    
    int min = n;
    std::vector <int> f(n, n);
    for (int i = n - 1; i >= 0; i--) {
        while (!p[t[i] - 'a'].empty() && min < p[t[i] - 'a'].back()) {
            p[t[i] - 'a'].pop_back();
        }
        if (!p[t[i] - 'a'].empty()) {
            int x = p[t[i] - 'a'].back();
            f[i] = x;
            min = std::min(min, x);
            if (i == x) {
                p[t[i] - 'a'].pop_back();
            }
        }
    }
    
    int max = -n;
    for (int i = 0; i < n; i++) {
        max = std::max(max, i - f[i]);
    }
    
    if (std::count(f.begin(), f.end(), n) || max > k) {
        std::cout << "-1\n";
        return;
    }
 
    std::cout << max << '\n';
    for (int i = 1; i <= max; i++) {
        std::string s1 = s;
        for (int j = 0; j < n; j++) {
            if (j - f[j] >= i) {
                s1[j] = s[j - 1];
            }
        }
        s = s1;
        std::cout << s << '\n';
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