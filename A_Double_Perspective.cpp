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
    int n;
    std::cin >> n;

    DSU dsu(2 * n);
    std::vector <int> edges;
    std::map <int, int> m;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
      
        if (!dsu.same(u, v)) {
            dsu.merge(u, v);
            ans++;
            edges.push_back(i + 1);
        }
    }

    std::cout << ans << '\n';
    for (int i = 0; i < ans; i++) {
        std::cout << edges[i] << " \n"[i == ans - 1];
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