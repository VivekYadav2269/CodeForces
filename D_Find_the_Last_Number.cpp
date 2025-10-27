#include <bits/stdc++.h>
using i64 = long long;

int query(int i, int x) {
    std::cout << "? " << i << ' ' << x << std::endl;
    int res; 
    std::cin >> res;
    return res;
}

void solve() {
    int n;
    std::cin >> n;
    
    int cnt = (n + 1) / 2;
    std::vector <int> odd, even;
    for (int i = 1; i < n; i++) {
        int x = query(i, 1);
        if (x) {
            odd.push_back(i);
            cnt--;
        } else {
            even.push_back(i);
        }
    }
    
    int ans = cnt ? 1 : 0;
    std::vector <int> find = cnt ? odd : even;
    for (int i = 1; (1 << i) + ans <= n; i++) {
        int k = 0;
        for (int j = (1 << i) + ans; j <= n;) {
            j += (1 << (i + 1));
            k++;
        }
        std::vector <int> pfind, afind;  
        for (int ele : find) {
            int x = query(ele, 1 << i);
            if (x) {
                pfind.push_back(ele);
                k--;  
            } else {
                afind.push_back(ele);
            }
        }
        if (k) {
            find = pfind;
            ans |= 1 << i;
        } else {
            find = afind;
        }
    }
    std::cout << "! " << ans << std::endl;
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