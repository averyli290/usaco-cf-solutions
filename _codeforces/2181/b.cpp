/*
Problem link: https://codeforces.com/problemset/problem/2181/B
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
Your chosen element will remain in your array anyways, so by next turn, if you do not use
your greatest element to either destroy or decrease enemy greatest elt, it may be destroyed

destroy or be destroyed.
*/


void solve() {
    int n, m; cin >> n >> m;
    priority_queue<int> a;
    priority_queue<int> b;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        a.push(x);
    }
    for(int i = 0; i < m; i++) {
        int x; cin >> x;
        b.push(x);
    }

    int ct = 0;
    while(!a.empty() && !b.empty()) {
        int aa = a.top();
        int bb = b.top();
        if (ct % 2 == 0) {
            b.pop();
            if (bb - aa > 0) b.push(bb - aa);
        } else {
            a.pop();
            if (aa - bb > 0) a.push(aa - bb);
        }
        ct++;
    }
    cout << ((ct % 2 == 1) ? "Alice" : "Bob") << endl;
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
