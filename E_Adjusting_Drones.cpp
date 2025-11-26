#include <bits/stdc++.h>
using i64 = long long;

struct DSU {
    std::vector <int> p, size;
    int component_count;
 
    DSU() : component_count(0) {}
    DSU(int n) {
        init(n);
    }
 
    void init(int n) {
        p.resize(n);
        std::iota(p.begin(), p.end(), 0);
        size.assign(n, 1);
        component_count = n;
    }
 
    void reset(int n) {
        p.clear();
        size.clear();
        init(n);
    }
 
    int find(int x) {
        if (x == p[x]) {
            return x;
        }
        return p[x] = find(p[x]);
    }
 
    bool same(int x, int y) {
        return find(x) == find(y);
    }
 
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return;
        }
 
        if (size[x] >= size[y]) {
            p[y] = x;
            size[x] += size[y];
        } else {
            p[x] = y;
            size[y] += size[x];
        }
        component_count--;
    }
 
    int Size(int x) {
        return size[find(x)];
    }
 
    int count_components() const {
        return component_count;
    }
};

void solve() {
    int n, k;
    std::cin >> n >> k;
    
    std::vector <int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i]--;
    }
    std::sort(a.begin(), a.end());

    std::vector <int> P(4 * n + 2), A(n);
    DSU dsu(4 * n + 2);
    std::vector <bool> vis(4 * n + 2);
    for (int i = n - 1; i >= 0; i--) {
        int p = dsu.find(a[i]);
        if (vis[p]) {
            P[p]++;
            A[i] = P[p];
            dsu.merge(p, A[i]);
        } else {
            P[p] = a[i];
            A[i] = P[p];
        }
        vis[A[i]] = true;
        if (A[i] - 1 >= 0 && vis[A[i] - 1]) {
            int x = P[dsu.find(A[i] - 1)];
            dsu.merge(A[i], A[i] - 1);
            P[dsu.find(A[i])] = std::max(x, A[i]);
        }
        if (vis[A[i] + 1]) {
            int x = P[dsu.find(A[i] + 1)];
            dsu.merge(A[i], A[i] + 1);
            P[dsu.find(A[i])] = std::max(x, A[i]);
        }
    }
        
    auto check = [&](int x) -> bool {
        std::vector <int> cnt(4 * n + 2);
        for (int i = 0; i < n; i++) {
            int y = std::min(A[i], x + a[i]);
            cnt[y]++;
        }
        return *std::max_element(cnt.begin(), cnt.end()) <= k;
    };
    
    int l = 0, h = n - 1;
    while (l < h) {
        int m = (l + h) / 2;
        if (!check(m)) {
            l = m + 1;
        } else {
            h = m;
        }
    }
    std::cout << l << '\n';
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