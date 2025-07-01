/*
Problem link: 
*/

#include <bits/stdc++.h>
typedef long long ll;
typedef std::pair<int, int> pii;

using namespace std;

void solve() {
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        bool zeroed = false;
        int count = 0;
        bool done = false;
        for (auto c : s) {
            if (c == '(') {
                count++;
                if (zeroed) {
                    cout << "YES" << endl;
                    done = true;
                    break;
                }
            } else {
                count--;
                if (count == 0) {
                    zeroed = true;
                }
            }
        }
        if (!done) {
            cout << "NO" << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

        solve();
    
}
/*
Problem link: 
*/

#include <bits/stdc++.h>
typedef long long ll;
typedef std::pair<int, int> pii;

using namespace std;

void solve() {
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        bool zeroed = false;
        int count = 0;
        bool done = false;
        for (auto c : s) {
            if (c == '(') {
                count++;
                if (zeroed) {
                    cout << "YES" << endl;
                    done = true;
                    break;
                }
            } else {
                count--;
                if (count == 0) {
                    zeroed = true;
                }
            }
        }
        if (!done) {
            cout << "NO" << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

        solve();
    
}
