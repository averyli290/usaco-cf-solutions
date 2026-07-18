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
try to place largest element
it will add no inversions

try to place smallest element that is free
you know how many inversions it will add
every empty space must be filled by a larger free element
all other values are known, 

place back to front

maintain to_place vector and prefix set
placing x at the last position adds (to_place.end() - lower_bound(all(to_place), x)) + (prefix.end() - lower_bound(all(prefix), x)) inversions 
binary search for the number

*/

void solve() {

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
