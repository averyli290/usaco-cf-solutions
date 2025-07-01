/*
Link: https://cp-algorithms.com/data_structures/sparse-table.html
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


const int MAX_N = 10e6;
const int K = 25;			// ceil(log(2, MAX_N))

vector<int> arr;
int lg[MAX_N + 1];	// lg[i] = floor(log_2(i))
int st[K + 1][MAX_N];		// st[i][j] = range query over [j, j + 2^i - 1]
// 
// // combine function depends on range query specs
int st_combine(int x, int y) {
	// combine function for min
	return min(x, y);
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

int main() {
	// precompute log
	lg[1] = 0;
	for (int i = 2; i <= MAX_N; i++) {
		lg[i] = lg[i / 2] + 1;
	}

	int n; cin >> n;
	arr.assign(n, 0);

}