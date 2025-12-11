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
greedy solve by figuring out how many ? come after an I and
how many do not

*/

void solve() {
    int n, q; cin >> n >> q;
    string s; cin >> s;
    int numq = 0;
    int numgq = 0;// good question marks
    int aftItot = 0;
    int beforeOthertot = 0;
    int prev = 0;
    int prevchar = 'x';
    for(int i = 1; i < n; i++) {
        if (s[i] == '?' && prev == -1) prev = i;
        if (s[i] != '?') {
            if(prev == -1) continue;
            if (s[i] == 'I') {
                beforeI.push_back({prev, i});
                beforeItot += i - prev;
            }
            else {
                beforeOther.push_back({prev, i});
                beforeOthertot += i - prev;
            }
            prev = -1;
        }
    }
    if (prev != -1) {
        beforeOther.push_back({prev, n});
        beforeOthertot += n - prev;
        debug(n - prev);
    }
    debug(beforeItot);
    debug(beforeOthertot);

    while (q--) {
        int cx, cv, ci; cin >> cx >> cv >> ci;
        int tempa = numgq;
        while (tempa > 0) {
            tempa -= min(tempa, cx);
        }
    }
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
