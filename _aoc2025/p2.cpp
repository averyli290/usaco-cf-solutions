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

set<ll> s;

set<ll> divisors(ll num) {
    set<ll> ret;
    for(ll i = 1; i * i <= num; i++) {
        if (num % i == 0) {
            ret.insert(num / i);
            ret.insert(i);
        }
    }
    return ret;
}

ll calc(ll start, ll end) {
    ll total = 0LL;
    for(ll i = start; i <= end; i++) {
        string str = to_string(i);
        int l = str.length();
        if (s.count(i) != 0) continue;
        set<ll> divs = divisors(l);
        for (ll d : divs) {
            if (l / d <= 1) continue;
            bool good = true;
            for(int j = 0; j < l; j += d) {
                if (str.substr(j, d) != str.substr(0, d)) {
                    good = false;
                    break;
                }
            }
            if (good) {
                total += i;
                s.insert(i);
                break;
            }
        }
    }
    return total;
}

void solve() {
    ll start, end;
    char c;
    cin >> start >> c >> end;
    ll ans = 0LL;
    ans += calc(start, end);

    while (cin >> c) {
        cin >> start;
        cin >> c;
        cin >> end;
        ans += calc(start, end);
    }

    for(ll v : s) {
        cout << v << endl;
    }

    cout << ans << endl;

    for(ll v : divisors(3)) {
        cout << v << " ";
    }
    cout << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    
}
