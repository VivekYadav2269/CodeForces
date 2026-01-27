#include <bits/stdc++.h>
using i64 = long long;

const int N = 1E6 + 1;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector a(n, std::vector <int> ());
    std::vector <int> b(n), mex(n);
    std::map <int, i64> impact;
    std::vector <std::map <int, int>> cnt(n);
    for (int i = 0; i < n; i++) {
        int l;
        std::cin >> l;
        b[i] = l;
        std::vector <int> v(l);
        for (int j = 0; j < l; j++) {
            std::cin >> v[j];
            cnt[i][v[j]]++;
        }
        std::sort(v.begin(), v.end());
        int k = 0;
        for (int j = 0; j < l; j++) {
            if(v[j] == k) {
                k++;
            }
        }
        mex[i] = k;
        a[i] = v;
        k++;
        for (int j = 0; j < l; j++) {
            if (v[j] == k) {
                k++;
            }
        }
        impact[mex[i]] += k - mex[i];
    }
    
    i64 ans = 0, sum = std::accumulate(mex.begin(), mex.end(), 0LL);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < b[i]; j++) {
            ans += (n - 1) * (sum - std::max(0, mex[i] - (cnt[i][a[i][j]] == 1 ? a[i][j] : mex[i]))) + impact[a[i][j]];
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