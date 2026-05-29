/*
Problem link: https://codeforces.com/contest/2230/problem/D
*/

#include <bits/stdc++.h>

using namespace std;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define debug(x) cout << #x << " is " << x << endl;
const long long INF = 1e18;

/*

first occurrence of 1 must be on same day, after that 2

*/


void solve() {
    int n; cin >> n;
    vi a(n), b(n);
    for(int i = 0 ;i < n; i++) cin >> a[i];
    for(int i = 0 ;i < n; i++) cin >> b[i];
    ll ans = 0LL;
    map<int, int> ma;
    map<int, int> mb;
    int right = 0;
    bool good = true;
    int cur = 1;
    for(int left = 0; left < n; left++) {
        right = max(right, left);
        while(good) {
            ans += right - left;
            right++;
            int ctr = 0;
            if (a[right] == cur) ctr++;
            if (b[right] == cur) ctr++;
            ma[a[right]]++;
            mb[b[right]]++;
            if (ctr == 1) {
                good = false;
            }
            if (ctr == 2) cur++;
        }
        ma[a[left]]--;
        mb[b[left]]--;
        if (!good) {
            if (ma[1] == 0 && mb[1] == 0 || (ma[1] == 1 && )) good = true;
        }
    }

    while (left < right) {
        ans += right - left;
        left++;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    
}
