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

int query(int x, int y) {
    cout << "? " << x << " " << y << endl;
    cout.flush();
    int r; cin >> r;
    return r;
}

void solve() {
    int x = query(2, 2);
    int y = query(2, 4);
    int z = query(4, 2);

    pii q;
    int a;
    if (x) {
        q = {3,2};
        a = query(3, 2);
    } else if (y) {
        q = {3,4};
        a = query(3, 4);
    } else if (z) {
        q = {5,2};
        a = query(5, 2);
    } else {
        q = {5,4};
        a = query(5, 4);
    }
    pii q2;
    if (!a) {
        q2 = {q.first - 2, q.second - 1};
    } else {
        q2 = {q.first, q.second - 1};
    }
    int a2 = query(q2.first, q2.second);
    cout << "! ";
    if (!a && !a2) {
        cout << q.first - 2 << " " << q.second << endl;
    } else if (!a && a2) {
        cout << q2.first << " " << q2.second << endl;
    } else if (a && !a2) {
        cout << q.first - 1 << " " << q.second << endl;
    } else {
        cout << q2.first - 1 << " " << q2.second << endl;
    }
    cout.flush();
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
