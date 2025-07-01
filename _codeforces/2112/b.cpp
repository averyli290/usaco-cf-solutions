/*
Problem link: https://codeforces.com/contest/2112/problem/B
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


void solve() {
	int n; cin >> n;
	vi a(n, 0);
	for(int i = 0; i < n; i++) { cin >> a[i]; }
	for(int i = 1; i < n; i++) {
		if (abs(a[i] - a[i - 1]) <= 1) {
			cout << 0 << endl;
			return;
		}
	}
	bool up = a[1] - a[0] > 0;
	for(int i = 1; i < n; i++) {
		if (up && a[i] - a[i - 1] <= 0) {
			cout << 1 << endl;
			return;
		} else if (!up && a[i] - a[i - 1] >= 0) {
			cout << 1 << endl;
			return;
		}
	}
	cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
