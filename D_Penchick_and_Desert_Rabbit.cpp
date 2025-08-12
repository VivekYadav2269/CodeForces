#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct DSU {
    vector <vector <int>> p;
    vector <int> size;
    
    DSU() : size(0) {} 
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        p.resize(2, vector <int> (n, 0));
        iota(p[0].begin(), p[0].end(), 0);
        size.assign(n, 1);
    }
    
    void reset(int n) {
        p.clear();
        size.clear();
        init(n);
    }
    
    int find(int x) {
        if (x == p[0][x]) {
            return x;
        }
        return p[0][x] = find(p[0][x]);
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
            p[0][y] = x;
            size[x] += size[y];
        } else {
            p[0][x] = y;
            size[y] += size[x];
        }
    }
    
    int Size(int x) {
        return size[find(x)];
    }
    
};

void solve() {
    int n;
    cin >> n;
    
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    
    DSU dsu(n);
    multimap <int, int> s;
    for (int i = 0; i < n; i++) {
        auto it = s.upper_bound(a[i]);
        if (it == s.end()) {
            s.insert({a[i], i});
            int j = dsu.find(i);
            dsu.p[1][j] = max(dsu.p[1][j], a[i]);
        } else {
            int last;
            while (it != s.end()) {
                last = it -> second;
                dsu.merge(i, last);
                it = s.erase(it);
            }
            s.insert({a[last], last});
            int j = dsu.find(i);
            dsu.p[1][j] = max(dsu.p[1][j], a[last]);
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << dsu.p[1][dsu.find(i)] + 1 << " \n"[i == n - 1];
    }
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