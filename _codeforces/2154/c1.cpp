/*
Problem link: https://codeforces.com/contest/2154/problem/C1
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
#define debug(x) cout << #x << " is " << x << endl;
#define debug_array(arr , n)  for(int i=1 ; i<=n ; i++) cout<<#arr<<"["<<i<<"] is "<< arr[i]<<endl;
#define debug_vector(arr , n) for(int i=0 ; i<n ; i++) cout<<#arr<<"["<<i<<"] is "<<arr[i]<<endl;
const long long INF = 1e18;


void solve() {
    int n; cin >> n;
    vi a(n), b(n);
    int evenct = 0;
    map<int, int> mp;
    for(int i = 0 ; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0 ; i < n; i++) {
        cin >> b[i];
    }
    bool done = false;
    for(int i = 0; i < n; i++) {
        if (done) break;
        int temp = a[i];
        for(int d = 2; d * d <= temp; d++) {
            if (temp % d == 0) {
                if (mp[d] > 0) {
                    done = true;
                }
                mp[d]++;
                while(temp % d == 0) temp /= d;
            }
        }
        if (temp > 1) {
            if (mp[temp] > 0) {
                done = true;
            }
            mp[temp]++;
        }
    }
    if (done) {
        cout << 0 << endl;
        return;
    }
    for(int i = 0; i < n; i++) {
        if (done) break;
        int temp = a[i] + 1;
        for(int d = 2; d * d <= temp; d++) {
            if (temp % d == 0) {
                if (mp[d] > 0) {
                    done = true;
                }
                while(temp % d == 0) temp /= d;
            }
        }
        if (temp > 1) {
            if (mp[temp] > 0) {
                done = true;
            }
        }
    }
    if (done) cout << 1 << endl;
    else cout << 2 << endl;

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
