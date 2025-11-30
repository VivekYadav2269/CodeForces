#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::string S, T;
    std::cin >> S >> T;

    std::vector <int> s(n), t(n);
    for (int i = 0; i < n; i++) {
        s[i] = S[i] - '0';
        t[i] = T[i] - '0';
    }
        
    std::vector <std::array <int, 2>> ans;
    for (int i = 0; i < n - 4; i++) {
        if (s[i] != t[i]) {
            int idx = std::find(s.begin() + i + 1, s.end(), s[i]) - s.begin();
            if (idx == n) {
                for (int j = i + 2; j < n; j++) {
                    s[j] ^= 1;
                }
                ans.push_back({i + 1, n - 1});
                idx = i + 1;
            } else {
                for (int j = i + 1; j <= idx; j++) {
                    s[j] ^= 1;
                }
            }
            ans.push_back({i, idx});
        }
    }
    
    auto Do = [&](std::vector <int> b) -> std::vector <std::array <int, 2>> {
        int x = 0;
        for (int i = 0; i < 4; i++) {
            if (b[3 - i]) {
                x |= 1 << i;
            }
        }
        
        std::vector <std::array <int, 2>> res;
        if (x == 1) {
            res.push_back({n - 3, n - 2});
            res.push_back({n - 3, n - 1});
        } else if (x == 2) {
            res.push_back({n - 4, n - 3});
            res.push_back({n - 4, n - 2});
        } else if (x == 3) {
            res.push_back({n - 2, n - 1});
        } else if (x == 4) {
            res.push_back({n - 2, n - 1});
            res.push_back({n - 3, n - 1});
        } else if (x == 5) {
            res.push_back({n - 3, n - 1});
            res.push_back({n - 4, n - 3});
            res.push_back({n - 4, n - 2});
        } else if (x == 6) {
            res.push_back({n - 3, n - 2});
        } else if (x == 7) {
            res.push_back({n - 3, n - 1});
        } else if (x == 8) {
            res.push_back({n - 3, n - 1});
            res.push_back({n - 4, n - 1});
        } else if (x == 9) {
            res.push_back({n - 3, n - 2});
            res.push_back({n - 4, n - 1});
        } else if (x == 10) {
            res.push_back({n - 4, n - 2});
            res.push_back({n - 2, n - 1});
            res.push_back({n - 3, n - 1});
        } else if (x == 11) {
            res.push_back({n - 4, n - 2});
            res.push_back({n - 3, n - 1});
            res.push_back({n - 4, n - 3});
            res.push_back({n - 4, n - 2});
        } else if (x == 12) {
            res.push_back({n - 4, n - 3});
        } else if (x == 13) {
            res.push_back({n - 3, n - 1});
            res.push_back({n - 4, n - 2});
            res.push_back({n - 2, n - 1});
            res.push_back({n - 3, n - 1});
        } else if (x == 14) {
            res.push_back({n - 4, n - 2});
        } else if (x == 15) {
            res.push_back({n - 4, n - 1});
        }
        return res;
    };
    std::vector <std::array <int, 2>> ss = Do({s[n - 4], s[n - 3], s[n - 2], s[n - 1]});
    for (auto [x, y] : ss) {
        ans.push_back({x, y});
    }
    std::vector <std::array <int, 2>> tt = Do({t[n - 4], t[n - 3], t[n - 2], t[n - 1]});
    for (auto [x, y] : std::views::reverse(tt)) {
        ans.push_back({x, y});
    }
    
    std::cout << ans.size() << '\n';
    for (auto [x, y] : ans) {
        std::cout << x + 1 << ' ' << y + 1 << '\n';
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