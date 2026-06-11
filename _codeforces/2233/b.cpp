/*
Problem link:  https://codeforces.com/contest/2233/problem/B
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
1 2 2 1 1 2 1 2
*/

void solve() {
    int n; cin >> n;
    while(n > 3) {
        // cout << n-2<<" "<<n-2<<" "<<n-1<<" "<<n-2<<" "<<n-1<<" "<<n<<" "<<n-2<<" "<<n<<" "<<n-1<<" "<<n-1<<" "<<n<<" "<<n<<" ";
        cout << n-1<<" "<<n<<" "<<n<<" "<<n-1<<" "<<n-1<<" "<<n<<" "<<n-1<<" "<<n<<" ";
        n -= 2;
    }
    if (n == 2) {
        cout << "1 2 2 1 1 2 1 2";
    } else {
        cout << "1 1 2 1 2 3 1 3 2 2 3 3";
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