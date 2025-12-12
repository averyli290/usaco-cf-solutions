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
    int n; cin >> n;
    vll evens, odds;
    for(int i = 0; i < n; i++) {
        ll x; cin >> x;
        if (x % 2 == 0) evens.push_back(x);
        else odds.push_back(x);
    }
    sort(all(evens));
    reverse(all(evens));
    sort(all(odds));
    reverse(all(odds));
    vll pref(sz(evens) + 1, 0);
    for(int i = 1;i <= sz(evens); i++) {
        pref[i] = pref[i - 1] + evens[i - 1];
    }
    // only the last odd selected will count, make the last one the max one before selecting any evens
    for (int i = 1; i <= n; i++) {
        // fit as many evens as possible
        if (sz(odds) == 0) {
            cout << 0 << " ";
            continue;
        }
        int num_evens = min(sz(evens), i - 1);
        int num_odds = i - num_evens;
        if (num_odds % 2 == 0) {
            if (num_evens >= 1 && num_odds + 1 <= sz(odds)) {
                num_evens -= 1;
                cout << odds[0] + pref[num_evens];
            } else {
                cout << 0;
            }
        } else {
            cout << odds[0] + pref[num_evens];
        }
        cout << " ";
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

