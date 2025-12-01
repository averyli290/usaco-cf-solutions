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


vector<vector<char>> grid;
set<pii> req;
vi primes;

bool in_bounds(int i, int j, int h, int w) {
    return (i >= 0) && (i < h) && (j >= 0) && (j < w);
}

bool is_corner(int i, int j, int h, int w, vector<vector<char>>& g) {
    if (!in_bounds(i, j, h, w)) return false;
    if (g[i][j] == '.') return false;
    bool top = false;
    bool left = false;
    if (!in_bounds(i - 1, j, h, w)) {
        top = true;
    } else if (g[i-1][j] == '.') {
        top = true;
    }
    if (!in_bounds(i, j - 1, h, w)) {
        left = true;
    } else if (g[i][j-1] == '.') {
        left = true;
    }
    return top && left;
}

bool check(int s, int h, int w, vector<vector<char>> gridcopy) {
    queue<pii> cur_req(all(req));
    while (!empty(cur_req)) {
        auto [a, b] = cur_req.front();
        cur_req.pop();
        // fill
        for (int i = a; i < a + s; i++) {
            for (int j = b; j < b + s; j++) {
                if (!in_bounds(i, j, h, w)) {
                    return false;
                }
                if (gridcopy[i][j] == '.')  {
                    return false;
                }
                gridcopy[i][j] = '.';
            }
        }
        // check more corners
        for (int i = a; i < a + s; i++) {
            if (is_corner(i, b + s, h, w, gridcopy)) {
                pii temp = pii{i, b+s};
                if (req.count(temp) == 0) {
                    cur_req.push(pii{i, b+s});
                }
            }
        }
        for (int j = b; j < b + s; j++) {
            if (is_corner(a+s, j, h, w, gridcopy)) {
                pii temp = pii{a+s, j};
                if (req.count(temp) == 0) {
                    cur_req.push(pii{a+s, j});
                }
            }
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (gridcopy[i][j] == '#') {
                return false;
            }
        }
    }
    return true;
}

void solve() {
    int h, w; cin >> h >> w;
    int lo = 1;
    int hi = min(h, w);
    grid.assign(h, vector<char>(w));
    req.clear();
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> grid[i][j]; 
            if (is_corner(i, j, h, w, grid)) req.insert(pii{i, j});
        }
    }

    int ans = 1;
    vi primes_to_check;
    for (int p : primes) {
        int cur = p;
        int curans = 1;
        if (!check(cur, h, w, grid)) continue;
        while (cur < 2500 && check(cur, h, w, grid)) {
            curans = cur;
            cur *= p;
        }
        primes_to_check.push_back(curans);
    }

    for (int p : primes_to_check) {
        ans *= p;
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 2501;
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] && (long long)i * i <= n) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }

    for(int i = 2; i <= n; i++) {
        if (is_prime[i]) primes.push_back(i);
    }


    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    
}
