/*
Problem link: https://codeforces.com/contest/2193/problem/B
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
the vet said ur fat...
https://www.youtube.com/watch?v=GzTAi3JQ3RM
*/

void solve() {
    int n; cin >> n;
    vi p(n);
    for(int i = 0; i < n; i++) cin >> p[i];

    vi ans;
    for(int i = 0; i < n; i++) {
        if (p[i] != n - i) {
            vi temp;
            for(int j = i; j < n; j++) {
                temp.push_back(p[j]);
                if (p[j] == n - i) {
                    reverse(all(temp));
                    ans.insert(ans.end(), all(temp));
                    for(int k = j + 1; k < n; k++) {
                        ans.push_back(p[k]);
                    }
                    for(int v : ans) cout << v << " ";
                    cout << endl;
                    return;
                }
            }
        }
        ans.push_back(p[i]);
    }
    for(int v : ans) cout << v << " ";
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
