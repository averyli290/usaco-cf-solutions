/*
Problem link:
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
123443212314

123...n123...n23...n123...n-2
12122112

*/

void solve() {
    int n; cin >> n;
    vi ans;
    for(int i = 0; i < n; i++) {
        ans.push_back(i % n + 1);
    }
    for(int i = 3; i < n+3; i++) {
        ans.push_back(i % n + 1);
    }
    for(int i = 1; i < n+1; i++) {
        ans.push_back(i % n + 1);
    }
    for(int i = 2; i < n+2; i++) {
        ans.push_back(i % n + 1);
    }
    for(int x : ans) {
        if (x == 0) cout << n << " ";
        else cout << x << " ";
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
