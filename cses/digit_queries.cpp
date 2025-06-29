/*
Problem link:
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

/*

numbers bounded by length of 18 because k <= 10^18 <= 18*10^18
9, 99, 999

for 10^ctr = 10...0000,
10^(ctr - 1) contained within each digit increase of first digit

*/

void solve() {
	int q; cin >> q;

	for(int i = 0; i < q; i++) {
		ll k; cin >> k;
		int ctr = 1;
		ll amt = 9;
		while (k - ctr * amt >= 0) {
			k -= ctr * amt;
			amt *= 10;
			ctr++;
		}
		if (k == 0) {
			cout << 9 << endl;
			continue;
		}

		//cout << "ctr " << ctr << endl;

		ll cur = pow(10, ctr - 1);
		cur += (k - 1) / ctr;
		int idx = (k - 1) % ctr;

		string s = to_string(cur);
		//cout << "s " << s << endl;
		cout << s[idx] << endl;

		// ll m = k % ctr;
		// //cout << m << endl;

		// ll cur = 1;
		// for(int j = 1; j < ctr; j++) {
		// 	cur *= 10;
		// }
		// // cout << "cur " << cur << endl;
		// cur += incr - 1;
		// string s = to_string(cur);
		// // cout << "s "<< s << endl;
		// cout << s[m] << endl;

	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}