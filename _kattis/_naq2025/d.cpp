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
#define debug_array(arr , n)  for(int i=1 ; i<=n ; i++) cout<<#arr<<"["<<i<<"] is "<< arr[i]<<endl;
#define debug_vector(arr , n) for(int i=0 ; i<n ; i++) cout<<#arr<<"["<<i<<"] is "<<arr[i]<<endl;
const long long INF = 1e18;


bool check(int i, int j, int r, int c, vector<string>& grid) {
    return (0 <= i) && (0 <= j) && (i < r) && (j < c) && grid[i][j] == '0';
}

void solve() {
    vector<pii> dir(4);
    dir[0] = pii{0, 1};
    dir[1] = pii{-1, 0};
    dir[2] = pii{0, -1};
    dir[3] = pii{1, 0};
    int r, c; cin >> r >> c;
    int is, js; cin >> is >> js;
    int ie, je; cin >> ie >> je;
    is--; js--; ie--; je--;
    vector<string> grid(r);
    for(int i = 0; i < r; i++) cin >> grid[i];

    int ctr = 0;
    int cx = is;
    int cy = js;
    int cd = 0;
    while (ctr < 10000+1) {
        if (cx == ie && cy == je) {
            cout << 1 << endl;
            return;
        }
        // attempt turn left
        pii leftdir = dir[(cd + 1) % 4];
        if (check(cx + leftdir.first, cy + leftdir.second, r, c, grid)) {
            cx += leftdir.first;
            cy += leftdir.second;
            cd = (cd + 1) % 4;
        } else if (check(cx + dir[cd].first, cy + dir[cd].second, r, c, grid)) {
            cx += dir[cd].first;
            cy += dir[cd].second;
        } else {
            cd = (cd - 1 + 4) % 4;
        }
        ctr++;
    }
    cout << 0 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    
}
