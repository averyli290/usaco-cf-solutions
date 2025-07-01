/*
Problem link: https://codeforces.com/problemset/problem/2070/C
*/

#include <bits/stdc++.h>
 
using namespace std;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const long long INF = 1e18;

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vi a(n, 0);
    for(int i=0;i<n; i++) cin >> a[i];
    
    int l = -1;
    int h = *max_element(all(a));
    int ans = h;
    
    while (h - l > 1) {
        int m = (h + l)/2;
        //cout << l << " " << m << " " << h << endl;
        
        bool ok;
        int ctr = 0;
        bool on_red = true;
        for (int i=0;i<n;i++) {
            if (a[i] > m) {
                if (on_red && s[i] == 'B') {
                    on_red = false;
                    ctr++;
                } else if (!on_red && s[i] == 'R') {
                    on_red = true;
                }
            }
        }
        ok = ctr <= k;
        
        if (ok) {
            ans = m;
            h = m;
        } else {
            l = m;
        }
    }
    //cout << l << " " << h << endl;

    cout << ans << endl;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}