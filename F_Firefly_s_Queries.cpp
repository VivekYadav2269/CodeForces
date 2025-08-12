#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        vector <int> a(n);
        vector <i64> pref(n + 1);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            pref[i + 1] = pref[i] + a[i];
        }
        auto query = [&](i64 i){
            int divi = i / n;
            int rem = i % n;
            i64 ans = divi * pref[n];
            if(rem > 0){
                if (divi + rem <= n) {
                    ans += pref[divi + rem] - pref[divi];
                }
                else{
                    ans += pref[divi + rem - n] + pref[n] - pref[divi];
                }
            }
            return ans;
        };
        while(q--){
            i64 l, r;
            cin >> l >> r;
            l--;
            i64 res = query(r) - query(l);
            cout << res << "\n";
        }
    }
    return 0;
}
// referred from jiangly.. i got stuck in this case 
//                "else{
//                    ans += pref[divi + rem - n] + pref[n] - pref[divi];
//                }"