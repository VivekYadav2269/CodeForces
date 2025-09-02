#include <bits/stdc++.h>
using i64 = long long;

std::vector <int> query(int u, int n) {
    std::cout << "? " << u << std::endl;
    std::vector <int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    return a;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
   
    int n;
    std::cin >> n;
    
    std::set <int> st;
    for (int i = 1; i < n; i++) {
        st.insert(i + 1);
    }
    
    std::vector <std::array <int, 2>> ans;
    std::array <int, 2> cnt {};
    std::vector <int> q, a = query(1, n);
    for (int i = 1; i < n; i++) {
        cnt[a[i] % 2]++;
        if (a[i] == 1) {
            ans.push_back({1, i + 1});
        }
    }
    if (cnt[0] > cnt[1]) {
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {
                q.push_back(i + 1);
                st.erase(i + 1);
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            if (a[i] == 2) {
                q.push_back(i + 1);
                st.erase(i + 1);
            }
        }
    }
    
    while (!q.empty()) {
        std::vector <int> nq;
        for (int Q = 0; Q < q.size(); Q++) {
            std::vector <int> d = query(q[Q], n);
            for (int i = 0; i < n; i++) {
                if (d[i] == 1 && st.contains(i + 1)) {
                    ans.push_back({q[Q], i + 1});
                } else if (d[i] == 2 && st.contains(i + 1)) {
                    nq.push_back(i + 1);
                    st.erase(i + 1);
                }
            }
        }
        q = nq;
    }
    
    std::cout << "!" << std::endl;
    for (int i = 0; i < n - 1; i++) {
        std::cout << ans[i][0] << ' ' << ans[i][1] << std::endl;
    }
    return 0;
}