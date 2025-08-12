    #include <bits/stdc++.h>
    using namespace std;
    using i64 = long long;

    int main(){
        int t;
        cin >> t;
        while (t--) {
            int n, l, r, s;
            cin >> n >> l >> r >> s;
            l--;
            
            int m = r - l;
            vector <int> gen(m);
            iota(gen.begin(), gen.end(), 1);
            
            s -= m * (m + 1) / 2;
            if (s < 0) {
                cout << -1 << "\n";
                continue;
            }
            
            int k = m - 1;
            while (s > 0) {
                gen[k]++;
                k--, s--;
                if (k == -1) {
                    k = m - 1;
                }
            }
            
            if (gen[r - l - 1] > n) {
                cout << -1 << "\n";
                continue;
            }
            
            vector <bool> mark(n, false);
            for (int i = 0; i < m; i++) {
                mark[gen[i]] = true;
            }
            
            k = 1;
            for (int i = 0; i < n; i++) {
                while (mark[k]) {
                    k++;
                }
                
                if (l <= i && i < r) {
                    cout << gen[i - l] << " \n"[i == n - 1];
                } else {
                    cout << k++ << " \n"[i == n - 1];
                }
            }
        }
        return 0;
    }