/*
Problem Link: https://codeforces.com/group/eH5P3JtXri/contest/640425/problem/J
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
#define debug_array(arr, n) for (int i = 1; i <= n; i++) cout << #arr << "[" << i << "] is " << arr[i] << endl;
#define debug_vector(arr, n) for (int i = 0; i < n; i++) cout << #arr << "[" << i << "] is " << arr[i] << endl;
const long long INF = 1e18;

/*
suffices to look at swapping adjacent elements

if weight R above top one
c1, w1, c2, w2

Want smallest out of
(v1-(c1 * (R + w2))) + (v2-(c2 * (R)))   // 1 on bottom
vs
(v1-(c1 * (R))) + (v2-(c2 * (R + w1)))   // 2 on bottom

(v1-(c1 * (R + w2))) + (v2-(c2 * (R)))   // 1 on bottom
=-(c1 * (R + w2)) + -(c2 * (R))
=-c1*R-c1*w2-c2*R
=-(c1+c2)*R - c1*w2

(v1-(c1 * (R))) + (v2-(c2 * (R + w1)))   // 2 on bottom
=-(c1+c2)*R - c2*w1

if -(c1 * w2) < -(c2 * w1), choose 1 on bottom
equivalent: -c1 / w1 < -c2 / w2
*/
 
void solve() {
  int n;
  cin >> n;
  vll w(n), v(n), c(n);
  vector<pair<double, ll>> a(n);
 
  ll tot = 0LL;
  for (ll i = 0; i < n; i++) {
    ll x, y, z;
    cin >> x >> y >> z;
    w[i] = x;
    v[i] = y;
    c[i] = z;
    tot += w[i];
  }
  for (ll i = 0; i < n; i++) {
    a[i] = {((double) -1 * c[i]) / w[i], i};
  }
  sort(all(a));
  ll ans = 0LL;
  ll curw = tot;
  for (ll i = 0; i < n; i++) {
    ll idx = a[i].second;
    curw -= w[idx];
    ans += v[idx] - c[idx] * curw;
  }
  cout << ans << endl;
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