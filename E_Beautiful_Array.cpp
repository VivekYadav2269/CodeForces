#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        map <int, vector <int>> m;
        for (int i = 0, x; i < n; i++) {
            cin >> x;
            m[x % k].push_back(x);
        }
        
        int checkSize = 0;
        for (auto &[_, x] : m) {
            sort(x.begin(), x.end());
            checkSize += (int)x.size() & 1;
        }
        
        if (checkSize < 2) {
            i64 ans = 1e18, res = 0;
            for (auto &[x, y] : m) {
                if ((int)y.size() % 2) {
                    int size = (int)y.size();
                    vector <int> one, last;
                    one.push_back(0);
                    last.push_back(0);
                    for (int i = 1; i < size; i += 2) {
                        one.push_back(one.back() + (y[i] - y[i - 1]) / k);
                    }
                    for (int i = size - 2; i >= 0; i -= 2) {
                        last.push_back(last.back() + (y[i + 1] - y[i]) / k);
                    }
                    
                    i64 res1 = LLONG_MAX, res2 = 0;
                    int d = (int)one.size();
                    for (int i = 0; i < d; i++) {
                        res2 = one[i] + last[d - 1 - i];
                        res1 = min(res1, res2);
                    }
                    res += res1;
                } else {
                    for (int i = 1; i < y.size(); i += 2) {
                        res += (y[i] - y[i - 1]) / k;
                    }
                }
                
            }
            ans = min(ans, res);
            cout << ans << '\n';
        } else {
            cout << -1 << '\n';
        }
    }

    return 0;
}
