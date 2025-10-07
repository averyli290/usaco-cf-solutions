/*
Problem link:
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
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int a = 0;
    int b = 0;
    int c = 0;
    for(char cc : s) {
        if (cc == '0') a++;
        if (cc == '1') b++;
        if (cc == '2') c++;
    }
    for(int i = 1; i <= a; i++) {
        cout << "-";
    }
    if (a + b + c == n) {
        for(int i = 0 ; i < c; i++) {
            cout << "-";
        }
    } else {
        if (a + b + 2 * c <= n) {
            for(int i = 0 ; i < c; i++) {
                cout << "?";
            }
            for(int i = 0; i < n - a - b - 2 * c; i++) {
                cout << "+";
            }
            for(int i = 0 ; i < c; i++) {
                cout << "?";
            }
        } else {
            for(int i = 0; i < n - a - b; i++) {
                cout << "?";
            }
        }
    }
    for(int i = 0; i < b; i++) {
        cout << "-";
    }
    cout << endl;
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
