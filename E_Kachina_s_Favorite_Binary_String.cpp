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
        
        vector <int> a(n);
        for (int i = 1; i < n; i++) {
            cout << "? " << 1 << ' ' << i + 1 << endl;
            int ans;
            cin >> ans;
            a[i] = ans;
        }
        
        if (a[n - 1] == 0) {
            cout << "! IMPOSSIBLE" << endl;
        } else {
            int i = 0;
            while (a[i] == 0) {
                i++;
            }
            string s(n, '0');
            for (int j = 0; j < i - a[i]; j++) {
                s[j] = '1';
            }
            for (int j = i; j < n; j++) {
                s[j] = (a[j] > a[j - 1] ? '1' : '0');
            }
            std::cout << "! " << s << endl;
        }
    }

    return 0;
}