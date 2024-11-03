#include<iostream>
#include<map>
#include<vector>

using namespace std;

int n;
char c;

int rec(int n, map<int, int>&d, map<int, int>::iterator start) {
    if (n == 0) {
        return 1;
    }
    if (n < 0) {
        return 0;
    }
    int total = 0;
    for (auto it = start; start != d.end(); it++) {
        int value = it->first;
        int count = it->second;
        if (count > 0) {
            d[value]--;
            total += rec(n - value, d, it);
            d[value]++;
        }
    }
    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    map<int, int>d;
    int t;
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (!d.count(t)) {
            d[t] = 0;
        }
        d[t] += 1;
    }

    cout << rec(15, d, d.begin()) << '\n';

}