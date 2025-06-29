#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s, cur; cin >> n;
    for(int i=0; i<n; i++) {
        cin >> s;
        int cur_max = 0;

        for(int j=0; j<s; j++) {
            cin >> cur;
            cur_max = max(1 + cur + (j / 2) + (s - j - 1) / 2, cur_max);
        }
        cout << cur_max << '\n';
    }

}
