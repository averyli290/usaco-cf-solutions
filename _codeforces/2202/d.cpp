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
at best, can force n * 2 - 1 moves using following pattern
1 2 3 1 4 2 5 3 6 4, ..., n, n - 2, n - 1, n 

pad end with pairs (n, n), (n - 1, n - 1) etc.

need k moves, can use numbers 1 to x and force 2x-1 moves
and then there are n-x remaining pairs at the end, so
(2x-1)+(n-x)
then (2x-1)+(n-x)=k -> x=k-n+1


*/

void solve() {
    int n, k; cin >> n >> k;
    if (k > 2 * n - 1 || k < n) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    if (diff == 0) {
        for(int i = 1; i <= n; i++) {
            cout << i << " " << i << " ";
        }
        cout << endl;
        return;
    }

    int front = k - n + 1;

    // takes front * 2 - 1 operations
    for(int i = 0; i < front; i++) {
        if (i == 0) cout << 1 << " " << 2 << " ";
        else if (i == front - 1) cout << front - 1 << " " << front << " ";
        else cout << i + 2 << " " << i << " ";
    }
    for(int i = front + 1; i <= n; i++) {
        cout << i << " " << i << " ";
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
