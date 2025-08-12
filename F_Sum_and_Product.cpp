#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        
        map <i64, i64> m;
        for (int i = 0, x; i < n; i++) {
            cin >> x;
            m[1ll * x]++;
        }
        
        auto findRoot = [&] (i64 sqr) -> i64 {
            i64 l = 0, r = sqrt(sqr) + 1ll;
            while (l < r) {
                i64 m = l + ((r - l) >> 1ll);
                if (m * m < sqr) {
                    l = m + 1;
                } else if (m * m == sqr) {
                    return m;
                } else {
                    r = m;
                }
            }
            return 0ll;
        };
        
        int q;
        cin >> q;
        
        while (q--) {
            i64 x, y;
            cin >> x >> y;
            
            if (x * x - 4 * y < 0) {
                cout << 0 << " \n"[q == 0];
            } else {
                i64 sq = findRoot(x * x - 4 * y), ans = 0ll;
                if ((x + sq) / 2 + (x - sq) / 2 != x || (x + sq) * (x - sq) / 4ll != y) {
                    cout << ans << " \n"[q == 0];
                } else {
                    ans += (x + sq) / 2 == (x - sq) / 2 ? 1ll * m[(x + sq) / 2] * (m[(x + sq) / 2] - 1) / 2 : 1ll * m[(x + sq) / 2] * m[(x - sq) / 2];
                    cout << ans << " \n"[q == 0];
                }
            }
        }
    }

    return 0;
}