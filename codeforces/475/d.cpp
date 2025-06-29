/*
Problem link: https://codeforces.com/contest/475/problem/D
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


const int MAX_N = 10e5;
const int K = 17;			// ceil(log(2, MAX_N))

vector<int> arr;
int lg[MAX_N + 1];			// lg[i] = floor(log_2(i))
int st[K + 1][MAX_N];		// st[i][j] = range query over [j, j + 2^i - 1]


int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}

// combine function depends on range query specs
int st_combine(int x, int y) {
	// combine function for gcd
	return gcd(x, y);
}

void st_construct() {
	// Construct using DP, O(NlogN)
	copy(arr.begin(), arr.end(), st[0]);						// initialize all st[0][j] = query over [j, j]
	for (int i = 1; i < K; i++) {
		for (int j = 0; j + (1 << i) <= MAX_N; j++) {	// calculate [i, j] = combine([i - 1, j], [i - 1, j + 2^(i - 1)])
			st[i][j] = st_combine(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
		}
	}
}

// query function depends on query specs
int st_query(int l, int r) {
	// query function for min, overlap two ranges where length is a power of 2
	int range_len_pow = lg[r - l + 1];
	return min(st[range_len_pow][l], st[range_len_pow][r - (1 << range_len_pow) + 1]);
}


void solve() {
	int n; cin >> n;

	arr.resize(n, 1);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	st_construct();

	for (int i = 0; i < K; i++) {
		for (int j = 0; j < n ; j++) {
			cout << st[i][j] << " ";
		}
		cout << endl;
	}

	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		ll ans = 0LL;
		int v; cin >> v;

		cout << ans << endl;
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	lg[1] = 0;
	for (int i = 2; i <= MAX_N; i++) {
		lg[i] = lg[i / 2] + 1;
	}
	
	solve();

}

/*
void solve() {
	int n; cin >> n;

	arr.resize(n, 1);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	st_construct();

	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		ll ans = 0LL;
		int v; cin >> v;

		int j = 0;
		while (j < n) {
			// find lower bound
			if (arr[j] % v == 0) {

				int left = j;
				while (left < n) {
					int k_lower = left;
					// find upper bound
					// get smallest k where gcd([j, k]) = v
					int st_i;
					do {
						st_i = lg[n - k_lower + 1];
						while (st_i >= 0 && st[st_i][k_lower] != v) {
							st_i--;
						}

						// update k_lower
						if (st_i >= 0) {
							k_lower = k_lower + (int) pow(2, st_i) - 1;
						}
					} while (st_i > 0);

					if (k_lower == left && arr[j] != v) {		// no range with j as index of lower bound and right bound >= left has gcd v
						//cout << "SKIP" << endl;
						break;
					}

					// get largest k s.t. gcd([j, k]) = v
					int k_upper = k_lower;
					do {
						st_i = lg[n - k_upper + 1];
						while (st_i >= 0 && st[st_i][k_upper] % v != 0) {
							st_i--;
						}
						// update k_upper
						if (st_i >= 0) {
							k_upper = k_upper + (int) pow(2, st_i) - 1;
						}

					} while (st_i > 0);

					// use j for left side of range, use anything from [k_lower, k_upper] for right side of range
					ans += k_upper - k_lower + 1;

					// update left
					left = k_upper + 2;
				}
			}
			j++;
		}
		cout << ans << endl;
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	lg[1] = 0;
	for (int i = 2; i <= MAX_N; i++) {
		lg[i] = lg[i / 2] + 1;
	}
	
	solve();

}

*/