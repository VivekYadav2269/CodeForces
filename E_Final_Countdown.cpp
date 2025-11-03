#include <bits/stdc++.h>
using i64 = long long;


void solve() {
    int n;
    std::cin >> n;
    
    std::string s;
    std::cin >> s;
    
    std::vector <int> pre(n);
    for (int i = 0; i < n - 1; i++) {
        pre[i + 1] = pre[i] + (s[i] - '0');
    }
    
    std::string ans = "";
    int carry = 0;
    for (int i = n - 1; i >= 0; i--) {
        int x = (s[i] - '0') + pre[i] + carry;
        carry = x / 10;
        if (i == 0) {
            std::string p = std::to_string(x);
            reverse(p.begin(), p.end());
            ans += p;
        } else {
            ans += std::to_string(x % 10);
        }
    }
    
    reverse(ans.begin(), ans.end());
    int i = 0;
    while (i < ans.size() && ans[i] == '0') {
        i++;
    }
    std::cout << ans.substr(i, ans.size() - i) << '\n';
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