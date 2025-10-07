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

/*
10
7 1 1 1 3 1 3 3 2 3

1 1 1 1 2 3 3 3 3 7

1 1 2 2 3 3 3 3 7

2 2 2 3 3 3 3 7

2 3 3 3 3 4 7

3 3 3 4 5 7

3 4 5 6 7

5 6 7 7


1 1 1 1 2 3 3 6 7


just try to contsruct it top down LOL

*/

void solve() {

    int n; cin >> n;
    vi a(n);
    ll s = 0LL;
    multiset<ll> m;
    priority_queue<ll> pq;
    for(int i = 0; i < n; i++) {
        ll x; cin >> x;
        a[i] = x;
        s += x;
        m.insert(x);
    }

    pq.push(s);
    int ctr = 0;
    while (!pq.empty() && ctr < n) {
        ll cur = pq.top();
        pq.pop();
        if (m.find(cur) != m.end()) {
            m.erase(m.find(cur));
        } else {
            ll a = cur / 2;
            ll b = cur - a;
            pq.push(a);
            pq.push(b);
            ctr++;
        }
    }
    if (sz(m) == 0) {
        cout << "YES" << endl;
        return;
    }
    //cout << ctr << endl;
    cout << "NO" << endl;


    // priority_queue<ll> pq;
    // multiset<ll> s;
    // for(int i = 0; i < n; i++) {
    //     ll x; cin >> x;
    //     //pq.push(-x);
    //     s.insert(x);
    // }
    // int ctr = n;
    // while(ctr > 1) {
    //     ll m = *min_element(all(s));
    //     //cout << m << endl;
    //     if (s.find(m + 1) != s.end()) {
    //         s.erase(s.find(m+1));
    //         s.erase(s.find(m));
    //         s.insert(2 * m + 1);
    //     } else {
    //         s.erase(s.find(m));
    //         if(s.find(m) != s.end())  {
    //             s.erase(s.find(m));
    //             s.insert(2 * m);
    //         } else {
    //             cout << "NO" << endl;
    //             return;
    //         }
    //     }
    //     ctr--;
    // }
    // cout << "YES" << endl;
    // return;
    // while (!pq.empty()) {
    //     ll a = pq.top();
    //     pq.pop();
    //     ll b = pq.top();
    //     pq.pop();
    //     if (abs(a-b) <= 1) {
    //         pq.push(a+b);
    //     } else {
    //         cout << a << " " << b << endl;
    //         cout << "NO" << endl;
    //         return;
    //     }
    // }
    // cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
