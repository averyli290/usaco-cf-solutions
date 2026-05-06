/*
Problem link:
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
const long long INF = 1e18;


void solve() {
    int n; cin >> n;
    string a, b; cin >> a >> b;

    if (a[0] == ')' || b[0] == ')' || a[n - 1] == '(' || b[n - 1] == '(') {
        cout << "NO" << endl;
        return;
    }
    // check totals are equal
    int fc = 0;
    int bc = 0;
    int fca = 0;
    int bca = 0;
    int fcb = 0;
    int bcb = 0;
    int swap1 = 0;
    int swap2 = 0;
    for(int i = 0; i < n; i++) {
        // debug(i);
        // debug(fca);
        // debug(bca);
        // debug(fcb);
        // debug(bcb);
        if (a[i] == ')' && b[i] == '(' && fcb > bcb) swap1++;
        if (a[i] == '(' && b[i] == ')' && fca > bca) swap2++;
        if (a[i] == '(') {
            fca++;
            fc++;
        } else {
            bca++;
            bc++;
        }
        if (b[i] == '(') {
            fcb++;
            fc++;
        } else {
            bcb++;
            bc++;
        }
        if (fc < bc) {
            cout << "NO" << endl;
            return;
        }
        if (fca < bca) {
            if (swap1 == 0) {
                cout << "NO" << endl;
                return;
            }
            fca++;
            fcb--;
            bca--;
            bcb++;
            swap1--;
        }
        if (fcb < bcb) {
            if (swap2 == 0) {
                cout << "NO" << endl;
                return;
            }
            fca--;
            fcb++;
            bca++;
            bcb--;
            swap2--;
        }
        if (fca < bca || fcb < bcb) {
            cout << "NO" << endl;
            return;
        }
    }

    // debug(fc);
    // debug(bc);
    // debug(fca);
    // debug(bca);
    // debug(fcb);
    // debug(bcb);
    if (fc != bc || fca != bca || fcb != bcb) cout << "NO" << endl;
    else cout << "YES" << endl;

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
