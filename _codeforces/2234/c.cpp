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
    int n; cin >> n;
    vll a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) {
        ll m=min(a[(i - 1 + n)%n], a[i]);
        // debug(m);
        vll b(n, 0ll);
        for(int j=1;j<n;j++) {
            int cur=(i+j)%n;
            int curprev=(i+j-1+n)%n;
            b[cur]=max(a[curprev],b[curprev]);
        }
        for(int j=0;j<n;j++) {
            int cur=(i-j+n)%n;
            int curprev=(i-j-1+n)%n;
            // debug(cur);
            // debug(curprev);
            // cout<<"mval:"<<max(a[curprev],b[cur])<<endl;
            // cout<<b[curprev]<<" ";
            if(b[curprev]>a[curprev]) b[curprev] = max(a[curprev],b[cur]);
            else break;
            // cout<<b[curprev]<<endl;
        }
        ll ans=0ll;
        for(int j=0;j<n;j++) ans+=b[j];
        // cout<<endl;
        cout<<ans<<" ";
        // cout<<endl;
        // for(int j=0;j<n;j++) if (b[j] < m) b[j]=m;
        // for(ll x : b) cout<<x<<" ";
        // cout<<endl;
        // ll curans=0ll;
        // vll c(n);
        // for(int j=1;j<n;j++) {
        //     int cur=(i+j)%n;
        //     curans+=min(b[(cur-1+n)%n], b[cur]);
        // }
        // cout<<curans<<" ";
        // cout<<endl;
    }
    cout<<endl;
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
