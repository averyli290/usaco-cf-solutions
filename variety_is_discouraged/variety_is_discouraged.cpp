#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        
        cin >> n;

        vector<int> l = vector<int>(n, 0);
        vector<int> ans = vector<int>(n, 0);
        vector<int> freq = vector<int>(n + 1, 0);

        for(int i = 0; i < n; i++) {
            cin >> l[i];
            freq[l[i]] += 1;
        }

        ans[0] = freq[l[0]] == 1 ? 1 : 0;
        for(int i = 1; i < n; i++) {
            if (freq[l[i]] == 1) {
                ans[i] = ans[i - 1] + 1;
            }
        }
        int m = *max_element(ans.begin(), ans.end());

        if (m == 0) {
            cout << 0 << endl;
        } else {
            for (int i = 0; i < n; i++) {
                if (ans[i] == m) {
                    cout << i - m + 2 << ' ' << i + 1 << endl;
                    break;
                }
            }
        }

    }


}
