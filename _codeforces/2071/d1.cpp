
/*
Problem link: https://codeforces.com/contest/2071/problem/D1
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> a;

int calc(ll m, ll n) {
    // basic cases
    if (m <= n) {
        return a[m];
    }
    if (m / 2 <= n) {
        int ans = 0;
        for(ll i = m / 2; i >= 1; i--) ans = (ans + a[i]) % 2;
        return ans;
    }
    
    if (n % 2 == 1) {
        int front = 0;
        int ans = 0;
        for(ll i = 1; i <= n; i++) front = (front + a[i]) % 2;
        while(m/2 > n) {
            ans = (ans + front) % 2;
            if ((m/2 - n) % 2 == 0) {
                return ans;
            } else {
                m /= 2;
            }
        }
        for(ll i = m / 2; i >= 1; i--) ans = (ans + a[i]) % 2;
        return ans;
    } else {
        int front = 0;
        int ans = 0;
        for(ll i = 1; i <= n; i++) front = (front + a[i]) % 2;
        // cout << "front before: " << front << endl;
        for(ll i = (n + 1) / 2; i >= 1; i--) front = (front + a[i]) % 2;// a[n + 1]
        // cout << "front after: " << front << endl;
        while (m/2 > n + 1) {
            // cout << "m / 2: " << m / 2 << endl;
            ans = (ans + front) % 2;
            if ((m/2 - (n + 1)) % 2 == 0) {
                return ans;
            } else {
                m /= 2;
            }
        }
        if (m / 2 == n + 1){
            for(ll i = n; i >= 1; i--) ans = (ans + a[i]) % 2;
            for(ll i = (n + 1) / 2; i >= 1; i--) ans = (ans + a[i]) % 2;
            return ans;
        }
        for(ll i = m / 2; i >= 1; i--) ans = (ans + a[i]) % 2;
        return ans;
    }
}

void solve() {
    ll n, l, r; cin >> n >> l >> r;
    a.assign(n + 1, 0);
    for(ll i = 1; i <= n; i++) cin >> a[i];

    cout << calc(l, n) << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}