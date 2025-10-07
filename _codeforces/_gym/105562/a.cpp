/*
Problem link: https://codeforces.com/gym/105562/problem/A
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
    vector<pair<string, string>> a(n);
    string t;
    getline(cin, t);
    for(int i = 0; i < n; i++) {
        string temp;
        getline(cin, temp);
        a[i].second = temp;
        for(int j = 0; j < sz(temp); j++) {
            if (isupper(temp[j])) {
                a[i].first = temp.substr(j, sz(temp) - j);
                break;
            }
        }
    }
    sort(all(a));
    for (auto p : a) {
        cout << p.second << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    
}
