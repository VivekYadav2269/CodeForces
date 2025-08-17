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
    int n;
    std::cin >> n;
    
    std::vector <std::array <int, 2>> a(n);
    std::vector <int> cnt(n);
    bool ok = true;
    DSU dsu(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i][0] >> a[i][1];
        a[i][0]--, a[i][1]--;
        cnt[a[i][0]]++, cnt[a[i][1]]++;
        if (a[i][0] == a[i][1]) {
            ok = false;
        }
        dsu.merge(a[i][0], a[i][1]);
    }
    
    if (!ok || *std::min_element(cnt.begin(), cnt.end()) < 2 || *std::max_element(cnt.begin(), cnt.end()) > 2) {
        std::cout << "NO" << '\n';
        return;
    }
    
    for (int i = 0; i < n; i++) {
        if (dsu.Size(i) & 1) {
            std::cout << "NO" << '\n';
            return;
        }
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