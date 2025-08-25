#include <bits/stdc++.h>
using i64 = long long;

int query1(int x, int n) {
    std::cout << "? " << x + 1 << ' ' << n << ' ';
    for (int i = 0; i < n; i++) {
        std::cout << i + 1 << ' ';
    }
    std::cout << std::endl;
    int res;
    std::cin >> res;
    return res;
}

int query2(int u, int v) {
    std::cout << "? " << u + 1 << ' ' << 2 << ' ' << u + 1 << ' ' << v + 1 << std::endl;
    int res;
    std::cin >> res;
    return res;
}

void solve() {
    int n;
    std::cin >> n;
    
    std::priority_queue <std::array <int, 2>> pq;
    for (int i = 0; i < n; i++) {
        int x = query1(i, n);
        pq.push({x, i});
    }
    
    std::vector <int> ans;
    int start = pq.top()[1], max = pq.top()[0];
    ans.push_back(start);
    pq.pop();
    
    while (!pq.empty() && pq.top()[0] == max) {
        pq.pop();
    }
    for (int i = max - 1; i > 0; i--) {
        bool got = false;
        while (!pq.empty() && pq.top()[0] == i) {
            if (!got) {
                int x = query2(ans.back(), pq.top()[1]);
                if (x == 2) {
                    ans.push_back(pq.top()[1]);
                    got = true;
                }
            }
            pq.pop();
        }
    }
    
    std::cout << "! " << max << ' ';
    for (int i = 0; i < max; i++) {
        std::cout << ans[i] + 1 << ' ';
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