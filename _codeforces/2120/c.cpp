/*
Problem link:
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


/*
min value achievable is n
max value is n * (n + 1) / 2

everything after 1 has d(x) = 1, can use as barrier
start with 1, 2, 3, ..., n, evey node has divineness 1

need to increase divineness by m - n, now dont need to keep track
of sum of things including and after the 1

iterate from n to 1, moving current node i to back of front array
increases divineness by i - 1, doesn't change anything after because
1 follows it directly, and doesn't change anything before it because
those paths don't use it.
*/

void solve() {
	ll n, m; cin >> n >> m;

	if (n > m || n * (n + 1) / 2 < m) {
		cout << -1 << endl;
		return;
	}

	vector<int> used;		// array placed at front before 1's 
							// ordered in descending order
	ll goal = m - n;

	// process greatest to least greedy, possible because differences of 1
	for(int i = n; i >= 1; i--) {
		// place current at end of front array increases d(i) by i - 1
		if (goal == 0) {
			break;
		}
		if (goal >= i - 1) {
			goal -= i - 1;
			used.push_back(i);
		}
	}
	
	if (used.size() == 0) {
		cout << 1 << endl;
		for(int i = 1; i < n; i++) {
			cout << i << " " << i + 1 << endl;
		}
		return;
	}

	bool b[1100001] = {0};
	cout << used[0] << endl;
	b[used[0]] = true;
	int prev = used[0];
	for (int i = 1; i < used.size(); i++) {
		cout << prev << " " << used[i] << endl;
		prev = used[i];
		b[prev] = true;
	}

	cout << prev <<  " " << 1 << endl;
	b[1] = true;
	prev = 1;
	for(int i = 1; i <= n; i++) {
		if (!b[i]) {
			cout << prev << " " << i << endl;
			prev = i;
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}