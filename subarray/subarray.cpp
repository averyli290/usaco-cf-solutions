#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n; cin >> t;
    for(int i=0; i<t; i++) {
        cin >> n;
        vector<int> v(n, 0);
        for(int j=0; j<n; j++) {
            cin >> v[j];
        }

        long long ans = 0;

        int r = 0;
        for (int l=0; l<n; l++) {
            while (r < n && v[r] >= r-l+1) {
                r++;
            }
            // either reached end of array or invalid
            if (v[r - 1] >= r-l) {
                ans += r-l;
            } else {
                ans += r-l-1;
            }
        }

        cout << ans << '\n';

        //
        // 1 2 3 1 2
        // l = 1
        // r = 3

    }

}
