/*
Avery Li
2/26/2025
Problem link: https://codeforces.com/contest/2049/problem/C
*/


/*
can greedily choose using a stack choosing the first dragon immediately to be 0
Proof:


a dragon can have at most three friends, so mex will be at most three

the mex for a dragon i's neighbors i-1 and i+1 

set a_1 = 0 

5 1 3

1: 5 2 3
2: 1 3
3: 1 2 4
4: 3 5
5: 1 4

1 = 0
5 = 1
2 = 1
3 = 1
4 = 2

5 1 5
1: 5 2
2: 1 3
3: 2 4
4: 3 5
5: 1 4

1 = 0
5 = 1
2 = 1
3 = 2
4 = 0

*/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <unordered_set>
#include <stack>

using namespace std;

vector<int> a;
vector<vector<int>> b;
vector<int> visited;
stack<int> s;
int n, x, y;

void solve() {
    cin >> n >> x >> y;
    x--;
    y--;
    a.assign(n, 3);
    b.assign(n, vector<int>());
    visited.assign(n, 0);
    s = stack<int>();
    for(int i = 0; i < n; i++) {
        b[i] = vector<int>({(i + n - 1) % n, (i + 1) % n});
        if (i == x) {
            b[i].push_back(y);
        } else if (i == y) {
            b[i].push_back(x);
        }
    }
    s.push(0);
    while (!s.empty()) {
        int cur = s.top();
        vector<int> friends = b[cur];
        s.pop();
        int used[4] = {0,0,0,0};
        for (auto& f : friends) {
            if (!visited[f]) {
                s.push(f);
            }
            used[a[f]] = 1;
        }
        int i = 0;
        while (i < 4 && used[i]) {
            i++;
        }
        a[cur] = i;
        visited[cur] = 1;
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
