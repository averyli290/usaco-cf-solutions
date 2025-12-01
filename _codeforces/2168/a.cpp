/*
Problem link: https://codeforces.com/contest/2168/problems/A
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
    string s; cin >> s;
    if (s == "first") {
        int n; cin >> n;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            cout << char('a' + (x - 1));
        }
    } else {
        string temp; cin >> temp;
        cout << temp.size() << endl;
        for(char c : temp) {
            cout << (c - 'a') + 1 << " ";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }
    
}