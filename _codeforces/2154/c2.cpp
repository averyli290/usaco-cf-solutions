/*
Problem link: https://codeforces.com/contest/2154/problem/C1
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


void solve() {
    int n; cin >> n;
    vi a(n);
    vll b(n);
    map<int, int> mp;
    vector<pll> temp(n);
    for(int i = 0 ; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0 ; i < n; i++) {
        cin >> b[i];
        temp[i] = {a[i], b[i]};
    }
    bool done = false;
    for(int i = 0; i < n; i++) {
        if (done) break;
        int temp = a[i];
        for(int d = 2; d * d <= temp; d++) {
            if (temp % d == 0) {
                if (mp[d] > 0) {
                    done = true;
                }
                mp[d]++;
                while(temp % d == 0) temp /= d;
            }
        }
        if (temp > 1) {
            if (mp[temp] > 0) {
                done = true;
            }
            mp[temp]++;
        }
    }
    if (done) {
        cout << 0 << endl;
        return;
    }
    ll ans = LLONG_MAX;
    for(int i = 0; i < n; i++) {
        int temp = a[i] + 1;
        for(int d = 2; d * d <= temp; d++) {
            if (temp % d == 0) {
                if (mp[d] > 0) {
                    done = true;
                    ans = min(ans, b[i]);
                }
                while(temp % d == 0) temp /= d;
            }
        }
        if (temp > 1) {
            if (mp[temp] > 0) {
                done = true;
                ans = min(ans, b[i]);
            }
        }
    }
    ll v1 = min(b[0], b[1]);
    ll v2 = max(b[0], b[1]);
    sort(all(temp));
    for(int i = 0; i < n - 1; i++) {
        if (temp[i].first > 1) ans = min(ans, (temp[i + 1].first - temp[i].first) * temp[i].second);
    }
    for(int i = 2; i < n; i++) {
        if (b[i] < v1) {
            v2 = v1;
            v1 = b[i];
        } else if (b[i] < v2) {
            v2 = b[i];
        }
    }
    ans = min(ans, v1 + v2);
    cout << ans << endl;
    // if (done) cout << ans << endl;
    // else cout << v1 + v2 << endl;

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
