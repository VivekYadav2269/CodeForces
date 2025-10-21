#include <bits/stdc++.h>
using i64 = long long;

const int N = 2E5 + 2;
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
    
    std::vector <int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
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
    
    std::vector <int> ord(n);
    std::iota(ord.begin(), ord.end(), 0);
    std::sort(ord.begin(), ord.end(), [&](int i, int j) {
        return b[i] < b[j];
    });
    
    i64 ans = b[ord[0]] + b[ord[1]];
    for (int i = 0; i < n; i++) {
        for (int x : mul[a[i]]) {
            cnt[x]--;
        }
        for (int x : mul[a[i] + 1]) {
            if (cnt[x]) {
                ans = std::min(ans, 1LL * b[i]);
            }
        }
        for (int x : mul[a[i]]) {
            cnt[x]++;
        }
    }
    
    for (int x : mul[a[ord[0]]]) {
        cnt[x]--;
    }
    
    for (int i = 2; i < N; i++) {
        if (cnt[i]) {
            int k = i - a[ord[0]] % i;
            if (k == i) {
                k = 0;
            }
            ans = std::min(ans, 1LL * k * b[ord[0]]);
        }
    }
    std::cout << ans << '\n';
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