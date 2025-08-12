#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        
        vector<int> a(n), lexiSmall(n), lexiLarge(n);
        vector<bool> vis(n + 1, false);
        set<int> s;
        for (int i = 1; i <= n; i++) {
            s.insert(i);
        }
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (!vis[a[i]]) {
                lexiSmall[i] = a[i];
                lexiLarge[i] = a[i];
                s.erase(a[i]);
                vis[a[i]] = true;
            }
        }

        for (int i = 1, j = 0; i <= n; i++) {
            while (j < n && lexiSmall[j] != 0) {
                j++;
            }
            if (j < n && !vis[i]) {
                lexiSmall[j++] = i;
            }
        }

        for (int i = 0, last = 0; i < n;) {
            if (lexiLarge[i] != 0) {
                last = lexiLarge[i++];
            } else {
                while (i < n && lexiLarge[i] == 0) {
                    if (!s.empty()) {
                        auto it = s.upper_bound(last);
                        if (it != s.begin()) {
                            --it;
                            last = *it;
                            s.erase(it);
                        } 
                    }
                    lexiLarge[i++] = last;
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            cout << lexiSmall[i] << " \n"[i == n - 1];
        }
        for (int i = 0; i < n; i++) {
            cout << lexiLarge[i] << " \n"[i == n - 1];
        }
    }

    return 0;
}