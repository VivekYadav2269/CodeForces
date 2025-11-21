#include <bits/stdc++.h>
using i64 = long long;

const int N = 2E5 + 1;
std::vector <int> primes;

void sieve() {
    std::vector <bool> check(N, true);
    for (int i = 2; i * i < N; i++) {
        if (!check[i]) {
            continue;
        }
        for (int j = i * i; j < N; j += i) {
            check[j] = false;
        }
    }
    
    for (int i = 2; i < N; i++) {
        if (check[i]) {
            primes.push_back(i);
        }
    }
}

void solve() {
    int n;
    std::cin >> n;
    
    int m = std::lower_bound(primes.begin(), primes.end(), n / 2) - primes.begin();
    if (m >= primes.size()) {
        m = primes.size() - 1;
    }
    std::vector <bool> vis(n + 1);
    std::vector <std::vector <int>> ans;
    for (int i = m; i >= 0; i--) {
        std::vector <int> res;
        for (int j = primes[i]; j <= n; j += primes[i]) {
            if (!vis[j]) {
                res.push_back(j);
                vis[j] = true;
            }
        }
        if (res.size() > 1) {
            ans.push_back(res);
        } else {
            for (int x : res) {
                vis[x] = false;
            }
        }
    }
    
    std::vector <int> Primes;
    for (int i = n; i >= 2; i--) {
        if (!vis[i]) {
            Primes.push_back(i);
        }
    }
    std::cout << 1 << ' ';
    int i = 0;
    for (auto v : ans) {
        std::cout << v[0] << ' ' << v[1] << ' ';
        for (int j = 2; j < v.size(); j += 2) {
            if (j + 1 < v.size()) {
                if (i < Primes.size()) {
                    std::cout << Primes[i] << ' ';
                    i++;
                }
                std::cout << v[j] << ' ' << v[j + 1] << ' ';
            } else {
                std::cout << v[j] << ' ';
            }
        }
    }
    
    for (; i < Primes.size(); i++) {
        std::cout << Primes[i] << ' ';
        
    }
    std::cout << '\n';
}
    
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    sieve();

    int t;
    std::cin >> t;
 
    while (t--) {
        solve();
    }
    
    return 0;
}