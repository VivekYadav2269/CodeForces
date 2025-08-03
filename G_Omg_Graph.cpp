#include <bits/stdc++.h>
using i64 = long long;

struct DSU {
    std::vector<int> p, size;
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
    int n, m;
    std::cin >> n >> m;

    std::vector <std::array <int, 3>> a(m);
    for (int i = 0; i < m; i++) {
        std::cin >> a[i][1] >> a[i][2] >> a[i][0];
        a[i][1]--, a[i][2]--;
    }
    std::sort(a.begin(), a.end());

    DSU dsu(n);
    std::vector <int> p(n, 1E9);
    i64 ans = 2E9;
    for (int i = 0; i < m; i++) {
        int par1 = dsu.find(a[i][1]);
        int par2 = dsu.find(a[i][2]);
        dsu.merge(a[i][1], a[i][2]);
        int par = dsu.find(a[i][1]);
        p[par] = std::min({p[par1], p[par2], p[par], a[i][0]});

        if (dsu.same(0, n - 1)) {
            int parent = dsu.find(0);
            ans = std::min(ans, 1LL * (p[parent] + a[i][0]));
        }
    }
    std::cout << ans << '\n';
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