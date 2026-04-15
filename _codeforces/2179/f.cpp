

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

/*
source  red

r <- g <- b
*/
string conv = "rgb";

void solve() {
    string s; cin >> s;
    if (s[0] == 'f') {
        int t; cin >> t;
        while (t--) {
            int n, m; cin >> n >> m;
            vector<vi> adj(n + 1, vi{});

            for(int i = 0; i < m; i++) {
                int x, y; cin >> x >> y;
                adj[x].push_back(y);
                adj[y].push_back(x);
            }

            vector<bool> vis(n + 1, false);
            queue<pii> q;
            q.push({1, 0});
            vi colorans(n + 1);
            vis[1] = true;
            while(!q.empty()) {
                auto [cur, color] = q.front();
                colorans[cur] = color;
                q.pop();
                for(int v : adj[cur]) {
                    if(!vis[v]) {
                        q.push({v, (color + 1) % 3});
                    }
                    vis[v] = true;
                }
            }
            for(int i = 1; i <= n; i++) {
                cout << conv[colorans[i]];
            }
            cout << endl;

        }
    } else {
        int t; cin >> t;
        while (t--) {
            int q; cin >> q;
            while(q--) {
                int d; cin >> d;
                string s; cin >> s;
                bool sr = false;
                bool sg = false;
                bool sb = false;
                for (int i = 0; i < d; i++) {
                    if(s[i] == 'r') sr = true;
                    if(s[i] == 'g') sg = true;
                    if(s[i] == 'b') sb = true;
                }
                if (sr && sg) {
                    for(int i = 0; i < d; i++)  {
                        if (s[i] == 'g') {
                            cout << i + 1 << endl;
                            break;
                        }
                    }
                }
                else if (sg && sb) {
                    for(int i = 0; i < d; i++)  {
                        if (s[i] == 'b') {
                            cout << i + 1<< endl;
                            break;
                        }
                    }
                }
                else if (sb && sr) {
                    for(int i = 0; i < d; i++)  {
                        if (s[i] == 'r') {
                            cout << i + 1 << endl;
                            break;
                        }
                    }
                } else {
                    cout << 1 << endl;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    
}
