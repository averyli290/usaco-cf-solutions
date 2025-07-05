/*
Problem link: https://codeforces.com/contest/2113/problem/D
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
want to make game last as long as possible
if you have a winning card, take the one that appears first and swap it with the smallest card greater than
the card before the winning card

if no winning card, move the greatest card last
*/

void solve() {
    int n; cin >> n;
    vi a(n); vi b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    vi prefa(n, 100); vi prefb(n, 100);
    prefa[0] = a[0]; prefb[0] = b[0];
    for (int i = 1; i < n; i++) {
        prefa[i] = a[i];
        prefa[i] = min(prefa[i - 1], prefa[i]);
    }
    for (int i = 1; i < n; i++) {
        prefb[i] = b[i];
        prefb[i] = min(prefb[i - 1], prefb[i]);
    }

    int ans = 0;
    int low = -1;
    int high = n + 1;
    for (auto v : prefa) {
        cout << v << " ";
    }
    cout << endl;
    for (auto v : prefb) {
        cout << v << " ";
    }
    cout << endl;
    while (high - low > 1) {
        int mid = (high + low) / 2;
        // cout << high << " " << mid << " " << low << endl;

        int ct = 0;
        if (ct >= mid) {
            ans = ct;
            low = mid;
        } else {
            high = mid;
        }
    }
    cout << ans << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}