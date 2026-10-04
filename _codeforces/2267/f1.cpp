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
*/

void solve() {
    int n, q; cin >> n >> q;
    vll a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(all(a));
    vll ans(100);
    ans[0] = a.back() - a.front();
    for(int i = 0; i < 99; i++) {
        priority_queue<ll> newa;
        for(int j = 0; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                newa.push(-(a[j] ^ a[k]));
            }
        }
        for(int j = 0; j < n; j++) {
            a[j] = -newa.top();
            newa.pop();
        }
        ans[i + 1] = a.back() - a.front();
    }
    while(q--) {
        int x; cin >> x;
        cout << ans[min(x, 99)] << endl;
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
