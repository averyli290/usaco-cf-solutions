/*
Problem link: https://codeforces.com/contest/2093/problem/F
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

let b_i be used for an optimal solution, then it contributes
(cur empty spaces) + (wrong steps) to the answer
summing over all b_i gives (n) + (sum of wrong steps)

work backwards?
if you choose one after another, it must have a correct where the other is NOT correct

then the cost will be (num correct at current) * 2 (for filling in, and for having set to empty from step before)
sum this over every step (n) * 2, but on the first step you dont have to fill in empty from before, so can 
subtract the amount of correct spaces

so answer is (n * 2) - # of words filled by best first choice
but now we only have to sum (num correct at current) * 2 for everything after the first one, of which
there are (n - # of words filled by best first choice) empty spaces after the first step.
so answer is n + (n - # of words filled by best first choice) * 2

after first choice, never have to make any empty space empty again after filling it.

optimal to choose most # of correct words for first choice

*/

void solve() {
    int n, m; cin >> n >> m;
    vector<string> a(n);
    vector<vector<string>> b(m, vector<string>(n));
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> b[i][j];
        }
    }

    vector<bool> ok(n);
    int best = 0;
    for(int i = 0; i < m; i++) {
        int cur = 0;
        for(int j = 0; j < n; j++) {
            if (b[i][j] == a[j]) {
                ok[j] = true;
                cur++;
            }
        }
        best = max(cur, best);
    }
    for(int i = 0; i < n; i++) {
        if(!ok[i]) {
            cout << -1 << endl;
            return;
        }
    }
    cout << n + (n - best) * 2 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}