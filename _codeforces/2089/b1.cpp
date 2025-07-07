/*
Problem link: https://codeforces.com/contest/2089/problem/B1
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
const long long INF = 1e18;

/*
for each a_i, calc how many rounds are required

the min interval where sum of interval in a is <= sum of interval in b

if current interval does not sat, then other ones using it cannot be sat,
they would not be using it if already sat and if not sat, then sum must still
be less after adding in current interval.

pref sums to calc interval sums
*/

void solve() {
    int n, k; cin >> n >> k;
    vll a(2 * n);
    vll b(2 * n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        b[i + n] = b[i];
    }
    vll prefa(2 * n + 1, 0);
    vll prefb(2 * n + 1, 0);
    for(int i = 0; i < 2 * n; i++) {
        prefa[i + 1] = a[i] + prefa[i];
        prefb[i + 1] = b[i] + prefb[i];
    }
    vi ans(n);
    stack<int> s;
    for(int i = 0; i < 2 * n; i++) {
        if (i < n) {
            s.push(i);
        }
        if (!s.empty()) {
            int t = s.top();
            // cout << "a sum: " << prefa[i + 1] - prefa[t] << endl;
            // cout << "b sum: " << prefb[i + 1] - prefb[t] << endl;
            // check if other intervals are sat also if most recent one is sat
            while (prefa[i + 1] - prefa[t] <= prefb[i + 1] - prefb[t]) {
                // cout << "t: " << t << endl;
                // cout << "a sum: " << prefa[i + 1] - prefa[t] << endl;
                // cout << "b sum: " << prefb[i + 1] - prefb[t] << endl;
                s.pop();
                ans[t] = i - t + 1;
                if (s.empty()) break;
                t = s.top();
            }
        }
    }
    cout << *max_element(all(ans)) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
