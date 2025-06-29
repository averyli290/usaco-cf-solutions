#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>


using namespace std;

void sta() {
    int N;
    cin >> N;
    
    vector<int> prefs(N);
    for (int i = 0; i < N; i++) {
        cin >> prefs[i];
    }
    
    unordered_map<int, unordered_set<int> > children;
    unordered_map<int, int> parents;
    vector<int> is_prefix(N + 1, 0);
    
    for (int i = 0; i <= N; i++) {
        children[i] = unordered_set<int>();
    }
    
    for (int i = 1; i <= N; i++) {
        is_prefix[prefs[i - 1]] = 1;
        children[prefs[i - 1]].insert(i);
        parents[i] = prefs[i - 1];
    }
    
    is_prefix[0] = 1;
    int M = N + 1 - accumulate(is_prefix.begin(), is_prefix.end(), 0);
    
    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
        int length = 0;
        bool found_branch = false;
        
        if (num == 0) {
            cout << 0 << endl;
        } else {
            while (num != 0) {
                int prev = num;
                num = parents[num];
                if (!found_branch && children[num].size() > 1) {
                    found_branch = true;
                }
                if (children[prev].empty()) {
                    children[num].erase(prev);
                }
                if (found_branch) {
                    length++;
                }
            }
            cout << length << endl;
        }
    }
}

int main() {
    sta();
    return 0;
}
