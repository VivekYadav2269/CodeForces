#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;

    while (t--) {
        i64 n, x;
        cin >> n >> x;
        
        bool ok = true, appeared = false;
        i64 res = 0, ans = 0;
        i64 msb = 0;
        for (int i = 60; i >= 0; i--) {
            if (x & (1ll << i)) {
                if (!(n & (1ll << i)) || appeared) {
                    ok = false;
                }
            } else {
                if (n & (1ll << i)) {
                    if (appeared) {
                        res |= 1ll << i;
                    } else if (!(x & (1ll << (i + 1))) && !(n & (1ll << (i + 1)))) {
                        appeared = true;
                        if (msb == 0) {
                            msb = 1ll << (i + 1);
                            res |= 1ll << i;
                        }
                    } else {
                        ok = false;
                    }
                }
            }
        }
        
        if (ok) {
            ans = n + msb - res;
            cout << ans << '\n';
        } else {
            cout << -1 << '\n';
        }
    }

    return 0;
}