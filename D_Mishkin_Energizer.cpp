#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    
    int L = 0, I = 0, T = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            L++;
        } else if (s[i] == 'I') {
            I++;
        } else {
            T++;
        }
    }
    
    if (L == n || I == n || T == n) {
        cout << -1 << '\n';
        return;
    }
    
    vector <int> ans;
    bool done = false;
    for (int i = 0; i < n - 1; i++) {
        int x = i;
        while (x < n - 1 && s[x] == s[x + 1]) {
            x++;
        }
        if (x == n - 1) {
            int times = x - i + 1;
            int size = ans.size();
            for (int j = 0; j < 2 * times; j++) {
                ans.push_back({size + i - 1 + j});
                // ans.push_back({size + i + 1});
            }
            done = true;
            break;
        }
        int times = x - i + 1;
        int size = ans.size();
        for (int j = 0; j < 2 * times; j++) {
            ans.push_back({size + x});
        }
        i = x;
    }
    
    int size = ans.size();
    // cout << "size : " << size << '\n';
    if (!done) {
        ans.push_back({size + n - 2});
        ans.push_back({size + n - 1});
    }
    
    size = ans.size();
    cout << size << '\n';
    for (int i = 0; i < size; i++) {
        cout << ans[i] + 1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
}