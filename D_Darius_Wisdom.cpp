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
        int ze = 0, on = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 0) {
                ze++;
            } else if (a[i] == 1) {
                on++;
            }
        }
        
        set <int> zero, one, two;
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) {
                zero.insert(i);
            } else if (a[i] == 1) {
                one.insert(i);
            } else {
                two.insert(i);
            }
        }
        
        vector <pair <int, int>> ans;
        for (int i = 0; i < ze; i++) {
            if (a[i] == 1) {
                auto ind = *zero.rbegin();
                zero.erase(ind);
                one.insert(ind);
                swap(a[i], a[ind]);
                ans.push_back({i + 1, ind + 1});
            } else if (a[i] == 2){
                auto ind = *one.rbegin();
                one.erase(ind);
                two.erase(i);
                two.insert(ind);
                one.insert(i);
                swap(a[i], a[ind]);
                ans.push_back({i + 1, ind + 1});

                auto in = *zero.rbegin();
                zero.erase(in);
                one.insert(in);
                swap(a[i], a[in]);
                ans.push_back({i + 1, in + 1});
            }
        }
        
        for (int i = ze; i < ze + on; i++) {
            if (a[i] == 2) {
                auto ind = *one.rbegin();
                one.erase(ind);
                swap(a[i], a[ind]);
                ans.push_back({i + 1, ind + 1});
            }
        }
        
        int size = (int)ans.size();
        cout << size << '\n';
        
        for (auto [x, y] : ans) {
            cout << x << ' ' << y << '\n';
        }
    }

    return 0;
}