#include <bits/stdc++.h>
using i64 = long long;

const int N = 2E5 + 1;
std::vector <std::vector <int>> mul(N);

void sieve() {
    std::vector <bool> check(N, true);
    for (int i = 2; i < N; i++) {
        if (check[i]) {
            mul[i].push_back(i);
        } else {
            continue;
        }
        for (int j = i + i; j < N; j += i) {
            check[j] = false;
            mul[j].push_back(i);
        }
    }
}

void solve() {
    int n;
    std::cin >> n;
    
    std::vector <int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
    }
    
    std::vector <int> cnt(N);
    for (int i = 0; i < n; i++) {
        for (int x : mul[a[i]]) {
            if (cnt[x]) {
                std::cout << 0 << '\n';
                return;
            }
            cnt[x]++;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int x : mul[a[i]]) {
            cnt[x]--;
        }
        for (int x : mul[a[i] + 1]) {
            if (cnt[x]) {
                std::cout << 1 << '\n';
                return;
            }
        }
        for (int x : mul[a[i]]) {
            cnt[x]++;
        }
    }
    std::cout << 2 << '\n';
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