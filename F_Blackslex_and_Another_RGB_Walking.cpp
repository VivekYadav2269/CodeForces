#include <bits/stdc++.h>
using i64 = long long;

const std::vector <char> colors = {'r', 'g', 'b'};

void first() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector adj(n, std::vector <int> ());
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    std::vector <char> c(n, '0');
    std::queue <int> q;
    q.push(0);
    c[0] = 'r';
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : adj[u]) {
            if (c[v] == '0') {
                c[v] = colors[(1 + std::find(colors.begin(), colors.end(), c[u]) - colors.begin()) % 3];
                q.push(v);
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        std::cout << c[i];
    }
    std::cout << '\n';
}

void second() {
    int q;
    std::cin >> q;
    
    for (int i = 0; i < q; i++) {
        int v;
        std::cin >> v;
        
        std::string c;
        std::cin >> c;
        
        int x = std::find(colors.begin(), colors.end(), c[0]) - colors.begin();
        if (c.find(colors[(x + 1) % 3]) != std::string::npos) {
            std::cout << c.find(colors[(x + 1) % 3]) + 1 << std::endl;
        } else {
            std::cout << 1 << std::endl;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string run;
    std::cin >> run;
    
    int t;
    std::cin >> t;
    
    while (t--) {
        if (run == "first") {
            first();
        } else {
            second();
        }
    }
    
    return 0;
}