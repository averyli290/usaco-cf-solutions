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
#define debug_array(arr, n)    \
  for (int i = 1; i <= n; i++) \
    cout << #arr << "[" << i << "] is " << arr[i] << endl;
#define debug_vector(arr, n)  \
  for (int i = 0; i < n; i++) \
    cout << #arr << "[" << i << "] is " << arr[i] << endl;
const long long INF = 1e18;
 
void solve() {
  int n;
  cin >> n;
  if (n % 4 == 0) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
  vi ans(32, -1);
  ans[0] = n % 2 == 0 ? 0 : -1;
  ans[31] = 1;
  for (int i = 1; i < 32; i++) {
    if (n % 2 == 0 && i == 1) continue;
    if (((n >> i) & 0b1) == 0b1) {
      ans[i - 1] = 1;
    }
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 8; j++) {
      cout << ans[i * 8 + j] << " ";
    }
    cout << endl;
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