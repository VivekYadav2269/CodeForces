#include <bits/stdc++.h>
using i64 = long long;

std::vector <int> primes;
const int N = 1E5 + 1;

void sieve() {
    std::vector <int> check(N, true);
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
    
    if (n == 2) {
        std::cout << "1 2\n";
        return;
    }
    
    int p = std::max(1, (n + 1) / 2);
    int i = 0;
    while (primes[i + 1] <= p) {
        i++;
    }
    
    std::vector <int> ans;
    for (int l = 1, r = 2 * primes[i] - 1; l <= r; l++, r--) {
        ans.push_back(l);
        if (l != r) {
            ans.push_back(r);
        }
    }
    for (int x = 2 * primes[i]; x <= n; x++) {
        ans.push_back(x);
    }
    
    for (int i = 0; i < n; i++) {
        std::cout << ans[i] << " \n"[i == n - 1];
    }
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