#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        
        vector <int> a(n);
        vector <i64> pre(n + 1);
        
        for(int i = 0; i < n; i++){
            cin >> a[i];
            pre[i + 1] = pre[i] + a[i];
        }
        
        int q;
        cin >> q;
        
        while(q--){
            int l, u;
            cin >> l >> u;
            l--; 
            
            int r = lower_bound(pre.begin(), pre.end(), pre[l] + u) - pre.begin();
            if (r > n) {
                r = n;
            }

            i64 ans1 = pre[r] - pre[l] - u;
            i64 ans2 = abs(pre[r - 1] - pre[l] - u) + 1;

            if(r - l == 1){
                cout << r << " \n"[q == 0];
            } 
            else if(ans1 < ans2){
                cout << r << " \n"[q == 0];
            }
            else{
                cout << r - 1 << " \n"[q == 0];
            }
        }
    }
    return 0;
}

/*
    0 9 10 16 23 29 32 42 49 52 62 */