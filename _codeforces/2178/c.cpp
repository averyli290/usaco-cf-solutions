/*
Problem link: https://codeforces.com/contest/2178/problem/C
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

/*

backwards

-4 2 3 -6 
-2
-4 3 -6

-4 3
5

7 -6 -1 -8 -8
6
7 -1 -8 -8
7


*/

void solve() {
    int n; cin >> n;
    vll a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    ll ans = 0LL;
    ll prev = a[0];
    for(int i = 1; i < n; i++) {
        if (prev < 0 && a[i] < 0) {
            ans -= a[i];
            cout << "second ";
        } else if (prev > 0 && a[i] > 0) {
            ans += prev;
            prev = a[i];
            cout << "first ";
        } else if (prev < 0 && a[i] > 0) {
            if (i == n - 1) {
                if (abs(a[i]) > prev) {
                    ans -= a[i];
                    cout << "second ";
                } else {
                    ans += prev;
                    cout << "first ";
                }
            } else {
                cout << "first ";
                ans += prev;
                prev = a[i];
            }
        } else {
            if (i == n - 1) {
                if (abs(a[i]) > prev) {
                    ans -= a[i];
                    cout << "second ";
                } else {
                    ans += prev;
                    cout << "first ";
                    prev = a[i];
                }
            } else {
                // if (abs(a[i]))
                // cout << "second ";
                // ans -= a[i];
                if (abs(a[i]) > prev) {
                    ans -= a[i];
                    cout << "second ";
                } else {
                    ans += prev;
                    cout << "first ";
                    prev = a[i];
                }
            }
        }
    }
    cout << endl;
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