/*
Problem link: https://codeforces.com/problemset/problem/1722/G
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
*/

void solve() {
    int n; cin >> n;
    if (n == 3) cout << "2 1 3";
    else if (n % 4 == 0) {
        int v1 = 8;
        int v2 = 9;
        for(int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                cout << v1 << " ";
                v1 += 2;
            } else {
                cout << v2 << " ";
                v2 += 2;
            }
        }
    }
    else if (n % 4 == 1) {
        cout << "2 0 4 5 3 ";
        int v1 = 8;
        int v2 = 9;
        for(int i = 0; i < n - 5; i++) {
            if (i % 2 == 0) {
                cout << v1 << " ";
                v1 += 2;
            } else {
                cout << v2 << " ";
                v2 += 2;
            }
        }
    }
    else if (n % 4 == 2) {
        cout << "4 1 2 12 3 8 ";
        int v1 = 16;
        int v2 = 17;
        for(int i = 0; i < n - 6; i++) {
            if (i % 2 == 0) {
                cout << v1 << " ";
                v1 += 2;
            } else {
                cout << v2 << " ";
                v2 += 2;
            }
        }
    } else {
        cout << "1 2 3 4 5 6 7 ";
        int v1 = 8;
        int v2 = 9;
        for(int i = 0; i < n - 7; i++) {
            if (i % 2 == 0) {
                cout << v1 << " ";
                v1 += 2;
            } else {
                cout << v2 << " ";
                v2 += 2;
            }
        }
    }
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
