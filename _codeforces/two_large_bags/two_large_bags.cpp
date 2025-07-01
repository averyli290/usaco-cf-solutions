/*
Avery Li
XX/XX/XXXX
Problem link: https://codeforces.com/contest/2067/problem/B
*/

/*

Numbers moved to second bag cannot be changed, only move there if there is
already a matching one in the first bag

must move the smallest elt to the second bag because if not then everything
in the second bag will be greater than that element.

(a and b are the first and second bags, respectively)

for every element in a, if it is not in b, might as well move it over to b
to ensure that it will be there by the above reasoning, everything in a 
can only increase and nothing in b can change.

then, once at least one of element x is matching in a and b, increase all
instances of x to x + 1 in bag a because they can possibly help increase the 
count of x + 1 to at least 2 to move 1 of them to b, and they are not useful
at value x anymore. Continue doing this for all elements x in a that have a count
greater than 0.

*/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> arr;
vector<int> a;
vector<int> b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        cin >> n;

        arr.assign(n, 0);
        int cons = n * 3;
        a.assign(cons, 0);
        b.assign(cons, 0);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            a[arr[i]]++;
        }

        sort(arr.begin(), arr.end());

        a[arr[0]]--;
        b[arr[0]]++;
        int cur = arr[0];

        while(cur < cons) {
            if (a[cur] > 1) {
                if (b[cur] == 0) {
                    a[cur]--;
                    b[cur]++;
                }
                a[cur + 1] += (a[cur] - 1);
                a[cur] = 1;
            }
            cur++;
        }

        bool good = true;
        for(int i = 0; i < cons; i++) {
            if (a[i] != b[i]) {
                good = false;
                break;
            }
        }
        if (good) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }

    }
}
