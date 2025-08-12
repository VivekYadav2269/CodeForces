#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
//     int t;
//     cin >> t;
    
//     while (t--) {
        string s;
        cin >> s;
        int q;
        cin >> q;
        
        int n = (int)s.size();
        set <int> store[26];
        for (int i = 0; i < n; i++) {
            store[s[i] - 'a'].insert(i);
        }
        for (int i = 0; i < q; i++) {
            int type;
            cin >> type;
            if (type == 1) {
                int pos;
                char c;
                cin >> pos >> c;
                pos--;
                
                store[s[pos] - 'a'].erase(pos);
                s[pos] = c;
                store[c - 'a'].insert(pos);
            } else {
                int l, r;
                cin >> l >> r;
                l--;
                
                int ans = 0;
                for (int i = 0; i < 26; i++) {
                    auto L = store[i].lower_bound(l);
                    ans += L != store[i].end() && r > *L;
                }
                cout << ans << '\n';
            }
        }
    // }

    return 0;
}