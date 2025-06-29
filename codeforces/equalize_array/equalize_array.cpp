#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    for (int o=0; o<t; o++) {
        int n; cin >> n;
        int v;

        unordered_map<int, int> m;
        for (int i=0; i<n; i++) {
            cin >> v;
            m[v]++;
        }

        int total_cost = 0;
        vector<int> values_vec;
        for(auto b : m) {
            values_vec.push_back(b.second);
            total_cost += b.second;
        }

        sort(values_vec.begin(), values_vec.end());

        vector<int> prefix_sums(values_vec.size(), 0);
        int s = 0;
        int cur_cost = total_cost;
        for (int i=0; i<values_vec.size(); i++) {
            s += values_vec[i];
            prefix_sums[i] = s;
        }

        int min_cost = total_cost;
        for (int i = 0; i < prefix_sums.size(); i++) {
            // obtain suffix sum using total - prefix_sums[i]
            //min_cost = min(min_cost, prefix_sums[i] + (int) (total_cost - prefix_sums[i] - values_vec[i] * (values_vec.size() - i)));
            min_cost = min(min_cost, (int) (total_cost - values_vec[i] * (values_vec.size() - i)));
        }
        cout << min_cost << '\n';

    }
}
