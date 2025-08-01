/*
Problem link: http://codeforces.com/contest/2124/problem/E
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include <numeric>
 
 
using namespace std;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
 
 
void solve() {
  int n; cin >> n;
  vll a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  ll total = accumulate(all(a), 0LL);
  if (total % 2 == 1) {
    cout << -1 << endl;
    return;
  }
 
  ll cur = 0;
  int idx = 0;
  for(; idx < n; idx++) {
      cur += a[idx];
      if (cur * 2 == total) {
        cout << 1 << endl;
        for(ll v : a) cout << v << " ";
        cout << endl;
        return;
      }
      if (a[idx] * 2 > total) {
        cout << -1 << endl;
        return;
      }
      if (cur * 2 > total) break;
  }
  // cout << "total: " << total << endl;
  // cout << "idx: " << idx<< endl;
  // balance out first part
  ll sub = (cur - (total - cur)) / 2;
  // cout << "sub: " << sub << endl;
  vll b(n, 0);
  b[idx] = sub;
  for(int i = 0; i < n; i++) {
    ll to_sub = min(a[i], sub);
    //cout << "to sub: " << to_sub << endl;
    b[i] = to_sub;
    sub -= to_sub;
    if (sub == 0) break;
  }
  cout << 2 << endl;
  for(ll v : b) {
    cout << v << " ";
  }
  cout << endl;
  for(int i = 0; i < n; i++) {
    cout << a[i] - b[i] << " ";
  }
  cout << endl;
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
 
  int t; cin >> t;
  while (t--) {
    solve();
  }
}