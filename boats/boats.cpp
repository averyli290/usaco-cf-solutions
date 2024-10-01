#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int t, n; cin >> t;

    for (int i=0; i<t; i++) {
        cin >> n;
        vector<int> w(n, 0);
        unordered_map<int, int> w_map;
        unordered_set<int> possible;
        unordered_set<int> weights;

        for (int j=0; j<n; j++) {
            cin >> w[j];
            w_map[w[j]] += 1;
            weights.insert(w[j]);
        }

        for(int a=0; a<n; a++) {
            for(int b=a+1; b<n; b++) {
                possible.insert(w[a] + w[b]);
            }
        }

        int maximum_teams = 0;
        for(int p : possible) {
            int cur = 0;
            for(int w: weights) {
                cur += min(w_map[w], w_map[p - w]);
            }
            //cout << '\n';
            cur /= 2;
            maximum_teams = max(maximum_teams, cur);
        }

        cout << maximum_teams << '\n';
        
    }
}