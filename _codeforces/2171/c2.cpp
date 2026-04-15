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
2 3 1 4 5
*/

void solve() {
    int n; cin >> n;
    vi a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int msb = 25;

    // flipping msb to your advantage beats all smaller bits

    while (msb >= 0) {
        int ans = -1;
        int ctr = 0;
        for(int i = 0; i < n; i++) {
            if (((a[i] >> msb) & 0b1) != ((b[i] >> msb) & 0b1)) {
                ans = i;
                ctr++;
            }
        }
        // flip odd number of times means someone has to win

        if (ctr % 2 == 1 && ans > -1) {
            if (ans % 2 == 0) {
                cout << "Ajisai" << endl;
                return;
            } else {
                cout << "Mai" << endl;
                return;
            }
        }
        msb--;
    }
    cout << "Tie" << endl;
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
