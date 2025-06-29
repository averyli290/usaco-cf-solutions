#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int t, n, s;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n >> s;

        int a;
        vector<int> verses(n, 0);
        vector<int> max_to_this_point(n, 0);
        vector<int> i_max_to_this_point(n, 0);
        int m = 0;
        int i_m = 0;

        for(int j=0; j<n; j++) {
            cin >> a;
            if (a > m) {
                m = a;
                i_m = j;
            }
            verses[j] = a;
            max_to_this_point[j] = m;
            i_max_to_this_point[j] = i_m + 1;
        }

        long long cur_sum = 0;
        int j = 0;
        int res_index = 0;
        while (j < n) {
            cur_sum += verses[j];
            if (cur_sum - max_to_this_point[j] > s) {
                break;
            }
            res_index = i_max_to_this_point[j];
            j++;
        }
        if (cur_sum <= s) {
            cout << 0 << '\n';
        } else {
            cout << res_index << '\n';
        }
    }
}