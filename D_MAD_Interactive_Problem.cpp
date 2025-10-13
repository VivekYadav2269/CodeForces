#include <bits/stdc++.h>
using i64 = long long;

int query(int k, std::vector <int> &v) {
    std::cout << "? " << k << ' ';
    for (int i = 0; i < k; i++) {
        std::cout << v[i] << ' ';
    }
    std::cout << std::endl;
    
    int res;
    std::cin >> res;
    return res;
}

void solve() {
    int n;
    std::cin >> n;
    
    std::vector <int> stk, at, ans(2 * n);
    stk.push_back(1);
    int j = 1;
    for (int i = 1; i < 2 * n; i++) {
        stk.push_back(i + 1);
        j++;
        int x = query(j, stk);
        if (x) {
            stk.pop_back();
            at.push_back(i + 1);
            ans[i] = x; 
            j--;
        }
    }
    
    for (int i = 0; i < 2 * n; i++) {
        if (!ans[i]) {
            at.push_back(i + 1);
            ans[i] = query(n + 1, at);
            at.pop_back();
        }
    }
    
    std::cout << "! ";
    for (int i = 0; i < 2 * n; i++) {
        std::cout << ans[i] << ' ';
    }
    std::cout << std::endl;
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