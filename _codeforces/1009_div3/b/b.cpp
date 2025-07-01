/*
Avery Li
XX/XX/XXXX
Problem link:
*/

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct Compare {
    bool operator()(const int& a, const int& b) {
        return a > b;
    }
};


void solve() {
    int n; cin >> n;
    priority_queue<int, vector<int>, Compare> pq;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        pq.push(a);
    }
    while (pq.size() > 1) {
        int b = pq.top();
        pq.pop();
        int c = pq.top();
        pq.pop();
        pq.push(b + c - 1);
    }
    cout << pq.top() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
