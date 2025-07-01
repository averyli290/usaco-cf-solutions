/*
Problem link: https://codeforces.com/contest/2104/problem/D
*/

#include <bits/stdc++.h>

using namespace std;
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const ll max_n = 1E7;
ll prime[max_n];
vll primes;

void sieve() {
	for(ll i = 0; i < max_n; i++) prime[i] = 1;
	prime[0] = 0; prime[1] = 0;
	primes = vll{};
	for(ll i = 2; i < max_n; i++) {
		if (prime[i]) {
			for(ll j = 2 * i; j < max_n; j+= i) {
				prime[j] = 0;
			}
			primes.push_back(i);
		}
	}
}

void solve() {
	ll n; cin >> n;
	vll a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(all(a));
	ll sum = accumulate(all(a), 0LL);
	ll primes_sum = accumulate(primes.begin(), primes.begin() + n, 0LL);
	ll ans = 0;
	//cout << sum << " " << primes_sum << endl;
	while(ans < n && sum < primes_sum) {
		sum -= a[ans];
		primes_sum -= primes[n - ans - 1];
		ans++;
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	sieve();

	int t; cin >> t;
	while (t--) solve();
}