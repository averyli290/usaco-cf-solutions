/*
Problem link: https://codeforces.com/contest/2191/problems/C
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

/*
take 1...10....0 and change to 0...01....1
game done when all 0's in front and 1's after

001011
101010

10101010
00101011
00001011

if 01 at the split point, sort the rest
00011111

01011101
11011001

111001011


101
1010 -> 0011
1011111000
0111111000

take all 1's before split point


*/

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int a = 0;
    int b = 0;
    for (int v : s) {
        if (v == '0') a++;
        else b++;
    }
    int i = 0;
    vi ans;
    while(i < a) {
        if (s[i] == '1') ans.push_back(i + 1);
        i++;
    }
    while(i < n) {
        if (s[i] == '0') ans.push_back(i + 1);
        i++;
    }
    if (sz(ans) == 0) {
        cout << "Bob" << endl;
    } else {
        cout << "Alice" << endl;
        cout << sz(ans) << endl;
        for(int v : ans) {
            cout << v << " ";
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
