/*
Problem link: https://codeforces.com/group/eH5P3JtXri/contest/647676/problem/J
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
    string x; cin >> x;
    int n; cin >> n;
    string s; cin >> s;
    if (x == "Decode") {
        bool same = true;
        for(int i = n - 1; i >= 0; i--) {
            if (s[i] != s[0]) same = false;
        }
        if (same) {
            cout << s << endl;
            return;
        }

        char twos;
        int numtwos = 0;
        int start=0;
        if (s[n - 1] != '2' && s[0] == '2') { // all 2's at start, take n - 1 to be the opposite
            if (s[n - 1] == '1') twos = '0';
            else twos = '1';
            for(int i = 0; i < n; i++) {
                if (s[i] != '2') {
                    start = i;
                    break;
                }
            }
        } else {
            int idx = n - 1;
            while (s[idx] != '2') idx--;
            while (s[idx] == '2') idx--;
            if (s[idx] == '0') twos = '1';
            else twos = '0';
            while (s[start] != '2') start++;
            while (s[start] == '2') start++;
        }
        int ctr = 0;
        string ans = "";
        start %= n;
        while (ctr < n) {
            if (s[start] == '2') {
                ans += twos;
            } else {
                ans += s[start];
            }
            ctr++;
            start = (start + 1) % n;
        }
        cout << ans << endl;

    } else {
        string s1 = s;
        bool same = true;
        for(int i = n - 1; i >= 1; i--) {
            if (s[i] == s[n - 1]) {
                s1[i] = '2';
            } else {
                same = false;
                break;
            }
        }
        same = same && (s[0] == s[n - 1]);
        if (same) {
            cout << s << endl;
            return;
        }
        cout << s1 << endl;
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
