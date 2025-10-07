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

/*
19 -> 10 decrease
take first sum from right where sum is >= 10
*/


int val(char c) {
    return c - '0';
}

void solve() {
    string s; cin >> s;
    int n = s.length();
    for(int i = n - 1; i >= 0; i--) {
        if (val(s[i]) + val(s[i - 1]) >= 10) {
            for(int j = 0; j < i - 1; j++) {
                cout << s[j];
            }
            cout << val(s[i]) + val(s[i - 1]);
            for(int j = i + 1; j < n; j++) {
                cout << s[j];
            }
            cout << endl;
            return;
        }
    }
    // default to maximizing first digit if cannot preserve number of digits
    cout << val(s[0]) + val(s[1]);
    for(int i = 2; i < n; i++) {
        cout << s[i];
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
