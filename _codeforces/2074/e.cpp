/*
Problem link: https://codeforces.com/problemset/problem/1807/F
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
cant explore all possibilties, guess at random, will pick best with 1/3 chance
*/

void solve() {
    random_device rd;
    mt19937 gen(rd());
    srand(time(NULL));
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
 
        vi v(n); for(int i = 1; i <= n; i++) v[i - 1] = i;
        shuffle(all(v), gen);
        vi g({v[0],v[1],v[2]});
        int resp;
        while(1) {
            cout << "? " << g[0] << " " << g[1] << " " << g[2] << endl; cout.flush();
            cin >> resp;
            if (resp == -1) return;
            if (resp == 0) {
                cout << "! " << g[0] << " " << g[1] << " " << g[2] << endl; cout.flush();
                break;
            }
            int r = rand();
            if (r % 3 == 0) {
                g = vi{g[0], g[1], resp};
            } else if (r % 3 == 1) {
                g = vi{g[0], g[2], resp};
            } else {
                g = vi{g[1], g[2], resp};
            }
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    solve();
}
