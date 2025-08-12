#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct DSU {
    vector <int> p, size;
    int component;
    
    DSU() : component(0) {} 
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        size.assign(n, 1);
        component = n;
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
        component--;
    }
    
    int Size(int x) {
        return size[find(x)];
    }
    
};

void solve() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    
    vector <pair <int, int>> ef(m1), eg(m2);
    for (auto &[x, y] : ef) {
        cin >> x >> y;
        x--, y--;
    }
    
    DSU f(n), g(n);
    for (auto &[x, y] : eg) {
        cin >> x >> y;
        x--, y--;
        g.merge(x, y);
    }
    
    int ans = 0;
    for (auto [x, y] : ef) {
        if (g.same(x, y)) {
            f.merge(x, y);
        } else {
            ans++;
        }
    }
    ans += f.component - g.component;
    
    cout << ans << '\n';
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}