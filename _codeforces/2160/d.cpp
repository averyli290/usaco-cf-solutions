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
find sequence where query is 0

for each index, include it, if value doesn't increase, keep, otherwise, exclude

*/

int query(vi &list) {
    cout << "? " << sz(list) << " ";
    for(int v : list) {
        cout << v << " ";
    }
    cout << endl;
    cout.flush();
    int res; cin >> res;
    return res;
}

/*

1 3 2 2 3 4 1 4

*/

void solve() {
    int n; cin >> n;

    vi query_later;
    vi zero_list;
    vector<bool> used(2 * n + 1, false);
    used[0] = true;
    vector<int> ans(2 * n + 1, 0);
    for(int i = 1; i <= 2 * n; i++) {
        vi temp = query_later;
        temp.push_back(i);
        int res = query(temp);
        if (res == 0) {
            query_later = temp;
        } else {
            used[i] = true;
            ans[i] = res;
            zero_list.push_back(i);
        }
    }

    for (int i = 1; i <= 2 * n; i++) {
        if (!used[i]) {
            vi temp = zero_list;
            temp.push_back(i);
            ans[i] = query(temp);
        }
    }

    cout << "! ";
    for(int i = 1; i <= 2 * n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    cout.flush();
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
