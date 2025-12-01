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


void solve() {
    int n; cin >> n;
    string base = "$1aA";
    int ctr = 0;
    vector<string> a({"ab","cd","ef","gh","ij","kl","mn","op","qr","st","uv","wx","yz"});
    for(int i = 0; i<13; i++) {
    for(int j = 0; j<13; j++) {
    for(int k = 0; k<13; k++) {
        if (ctr == n) return;
        string temp = base + a[i] + a[j] + a[k];
        cout << temp << endl;
        ctr++;
    }
    }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    
}
