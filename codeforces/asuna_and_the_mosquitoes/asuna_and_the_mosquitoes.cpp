/*
Avery Li
3/29/2025
Problem link: https://codeforces.com/contest/2092/problem/C
*/

/*
9 5 4 3 2
9 6 4 3 1
15 4 3 1
15 6 3 0
21 3 0

a . . . 
    x . 

    x . 
a . . . 

move all to even or all to odd first while still having at least one elt in both
after, ans = sum of everything - (number of odds - 1)

*/

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n; cin >> n;
    vector<ll> arr(n, 0);
    vector<ll> evens;
    vector<ll> odds;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] % 2 == 0) {
            evens.push_back(arr[i]);
        } else {
            odds.push_back(arr[i]);
        }
    }

    if (evens.size() == 0) {
        cout << *max_element(odds.begin(), odds.end()) << endl;
        return;
    }
    if (odds.size() == 0) {
        cout << *max_element(evens.begin(), evens.end()) << endl;
        return;
    }

    ll a = 0;
    for (int i = 0; i < odds.size(); i++) {
        a += odds[i];
    }
    for (int i = 0; i < evens.size(); i++) {
        a += evens[i];
    }
    a -= odds.size();
    a++;
    cout << a << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
