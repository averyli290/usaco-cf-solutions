/*
Problem link: https://codeforces.com/contest/2183/problems/C
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

    k
00001000000
00011000000

m/4
m

00001000000
2 * m / 3 + 1

7/3 * 2
4 + 1

m / 3
m / 3 + 1
m - (2m/3 + 1)

0001000 0
0002000 1
0003000 2
0031000 3
0212000 4
1113000 5
1111300 6
1112120 7


distribute m / 3 + 1 to the min side




*/

void solve() {
    int n, m, k; cin >> n >> m >> k;
    int left = k - 1;
    int right = n - k;
    int wait = min(left, right);
    wait -= 1;
    int ans = 0;
    int accum = m / 3 + 1;
    if (wait < m / 3 + 1) {
        accum = wait+1;
        // debug(wait);
        // debug(accum);
        if (wait >= 0) {
            // debug(wait);
            ans += accum;
            /*
             k
            0100
            1100
            1110
            */
            m -= wait;
            ans += m / 2 + 1;
        } else {
            ans = ((m - 1) / 2 + 1) + 1;
        }
    } else {
        ans += m / 3 + 1 + (m - (2*m / 3 + 1));
    }
    cout << min(ans, n) << endl;
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
