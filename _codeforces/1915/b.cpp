/*
Problem link:
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


void solve() {
    vector<vector<char>> a(3, vector<char>(3));
    int x;
    for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
        cin >> a[i][j];
        if (a[i][j] == '?') x=i;
    }
    }

    vector<bool> b(3, false);
    for(int i = 0; i < 3; i++) {
        if (a[x][i] != '?') b[a[x][i] - 'A'] = true;
    }

    for(int i = 0; i < 3; i++) {
        if (!b[i]) {
            if(i == 0) cout << 'A' << endl;
            if(i == 1) cout << 'B' << endl;
            if(i == 2) cout << 'C' << endl;
            break;
        }
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
