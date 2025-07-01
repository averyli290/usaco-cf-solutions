/*
Problem link: https://cses.fi/problemset/task/3221
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


// dequeue using two stacks
stack<pll> s1;      // enqueue to s1
stack<pll> s2;      // dequeue from s2

void enqueue_elt(ll x) {
    int minimum = s1.empty() ? x : min(x, s1.top().second);
    s1.push({x, minimum});
}

pll dequeue_elt() {
    if (s2.empty()) {
        while (!s1.empty()) {
            pll v = s1.top();
            s1.pop();
            int minimum = s2.empty() ? v.first : min(v.first, s2.top().second);
            s2.push({v.first, minimum});
        }
    }
    pii ret = s2.top();
    s2.pop();
    return ret;
}

int min_elt() {
    if (s1.empty() || s2.empty())  {
        return s1.empty() ? s2.top().second : s1.top().second;
    }
    return min(s1.top().second, s2.top().second);
}

void solve() {

    ll n, k; cin >> n >> k;
    ll x,a,b,c; cin >> x >> a >> b >> c;


    vector<ll > arr(n-k+1);

    for (int i = 0; i < k; i++) {
        enqueue_elt(x);
        x = (a * x + b) % c;
    }
    for (int i = 0; i < n - k + 1; i++) {
        arr[i] = min_elt();
        enqueue_elt(x);
        dequeue_elt();
        x = (a * x + b) % c;
    }

    ll res = arr[0];
    for (int i = 1; i < n - k + 1; i++) {
        res ^= arr[i];
    }

    cout << res << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    
}
