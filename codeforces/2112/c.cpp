/*
Problem link: https://codeforces.com/contest/2112/problem/C
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

/*
x + y + z > max
x + y > z
x + z > y
y + z > x
x <= y <= z
find number of triangles with x + y + z > max
*/

bool valid(int x, int y, int z) {
	// x <= y <= z
	return x + y > z;
}

void solve() {
	int n; cin >> n;
	vi a(n, 0);
	for(int i = 0; i < n; i++) { cin >> a[i]; }
	sort(a.begin(), a.end());

	int mx = a[n - 1];
	ll ans = 0;

    for (int i = 2; i < n; i++) {
        int left = 0, right = i - 1; 
        while (left < right) {
            if (a[left] + a[right] > a[i] && a[left] + a[right] + a[i] > mx) {
                ans += right - left; 
                right--; 
            } 
          	else {
                left++; 
            }
        }
    }
	cout << ans << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
