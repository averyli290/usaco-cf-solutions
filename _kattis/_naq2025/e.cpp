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

struct tmp {
    pii pos;
    char c;
};

double dist(double x, double y) {
    return sqrt((x - 144) * (x - 144) + (y - 84) * (y - 84));
}
bool cmp(tmp a, tmp b) {
    pii x = a.pos;
    pii y = b.pos;
    int val1 = (x.first - 144) * (x.first - 144) + (x.second - 84) * (x.second - 84);
    int val2 = (y.first - 144) * (y.first - 144) + (y.second - 84) * (y.second - 84);
    return val1 < val2;
}

void solve() {
    int ansr = 0;
    int ansy = 0;
    for(int i = 0; i < 10; i++) {
        int n; cin >> n;
        vector<tmp> stones;
        for(int j = 0; j < n; j++) {
            int x, y; cin >> x >> y;
            tmp cur = {{x, y}, 'r'};
            stones.push_back(cur);
        }
        cin >> n;
        for(int j = 0; j < n; j++) {
            int x, y; cin >> x >> y;
            tmp cur = {{x, y}, 'y'};
            stones.push_back(cur);
        }
        if (sz(stones) == 0) continue;
        sort(all(stones), cmp);
        char win = stones[0].c;
        int pts = 0;
        for(int j = 0; j < sz(stones); j++) {
            if (stones[j].c != win) break;
            pts++;
        }
        if (win == 'r') ansr += pts;
        else ansy += pts;
    }
    cout << ansr << " " << ansy << endl;
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
