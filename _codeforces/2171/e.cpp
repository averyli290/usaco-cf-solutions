
#include <bits/stdc++.h>

using namespace std;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define debug(x) cout << #x << " is " << x << endl;
#define debug_array(arr , n)  for(int i=1 ; i<=n ; i++) cout<<#arr<<"["<<i<<"] is "<< arr[i]<<endl;
#define debug_vector(arr , n) for(int i=0 ; i<n ; i++) cout<<#arr<<"["<<i<<"] is "<<arr[i]<<endl;
const long long INF = 1e18;

/*
2 3 1 4 5

n / 2 evens


n / 6 odd multiples of 3
-> index 2n/3
n / 10 odd multiples of 5

n/3 + n/15

 2 4 6 8 10 12
3 9 

n / 2 - n / 6 =
n / 3

A = 2x
B = 3x
AAXAACCAAXAABBAAXAACCAAXAABBAAXAACC

8 A 2n3n5
8 B 3n5
6 C 5
8 X

AAXAAXAAXAABBXBBXBBXBBCCXCCXCC

AAXAAX
BBXBB

BB
1/3 - 1/5
CC

6/7

1/3 + 2/15 + 1/10 = 15 + 4 + 3 = 22/30

10

1 2 3 4 5 6 7 8 9 10

28
14 evens
3 9 15
AAXAAXAAX
21

AAXAAX...BBXBBX...



*/

void solve() {
    int n; cin >> n;

    queue<int> q1;
    queue<int> q2;
    queue<int> q3;
    for(int i = 1; i <= n; i++) {
        if (i % 3 == 0) q2.push(i);
        else if (i % 2 == 0) q1.push(i);
        else q3.push(i);
    }

    while (sz(q1) >= 2 && !q3.empty()) {
        cout << q1.front() << " ";
        q1.pop();
        cout << q1.front() << " ";
        q1.pop();
        cout << q3.front() << " ";
        q3.pop();
    }
    if (!q1.empty()) q3.push(q1.front());
    while (sz(q2) >= 2 && !q3.empty()) {
        cout << q2.front() << " ";
        q2.pop();
        cout << q2.front() << " ";
        q2.pop();
        cout << q3.front() << " ";
        q3.pop();
    }
    if (!q2.empty()) q3.push(q2.front());
    while(!q3.empty()) {
        cout << q3.front() << " ";
        q3.pop();
    }
    cout << endl;



    /*
    string config = "AAXAAXAAXAABBXBBXBBXBBCCXCCXCC";
    vi twos = {2, 4, 8, 14, 16, 22, 26, 28};
    assert(sz(twos) == 8);
    vi threes = {3, 6, 9, 12, 18, 21, 24, 27};
    assert(sz(threes) == 8);
    vi fives = {5, 10, 15, 20, 25, 30};
    assert(sz(fives) == 6);
    vi other = {1, 7, 11, 13, 17, 19, 23, 29};
    assert(sz(other) == 8);
    int tw_ctr = 0;
    int th_ctr = 0;
    int fi_ctr = 0;
    int ot_ctr = 0;
    for(int i = 0; i < n; i += 1) {
        if (i % 30 == 0 && n - i < 30) {
            vi cur_threes;
            vi cur_evens;
            vi cur_others;
            int start = i + 1;
            for(int j = start; j <= n; j++) {
                if (j % 3 == 0) cur_threes.push_back(j);
                else if (j % 2 == 0) cur_evens.push_back(j);
                else cur_others.push_back(j);
            }
            int a = 0;
            int b = 0;
            int c = 0;
            while(a < sz(cur_evens) && c < sz(cur_others)) {
                cout << cur_evens[a] << " ";
                a++;
                if (a < sz(cur_evens))  {
                    cout << cur_evens[a] << " ";
                    a++;
                }
                cout << cur_others[c] << " ";
                c++;
            }
            for(int b = 0; b < sz(cur_threes); b++) {
                cout << cur_threes[b] << " ";
            }
            while (c < sz(cur_others)) {
                cout << cur_others[c] << " ";
                c++;
            }
            break;
        }
        char ch = config[i % 30];
        if (ch == 'A') {
            cout << twos[tw_ctr];
            twos[tw_ctr] += 30;
            tw_ctr = (1 + tw_ctr) % 8;
        } else if (ch == 'B') {
            cout << threes[th_ctr];
            threes[th_ctr] += 30;
            th_ctr = (1 + th_ctr) % 8;
        }else if (ch == 'C') {
            cout << fives[fi_ctr];
            fives[fi_ctr] += 30;
            fi_ctr = (1 + fi_ctr) % 6;
        } else {
            cout << other[ot_ctr];
            other[ot_ctr] += 30;
            ot_ctr = (1 + ot_ctr) % 8;
        }
        cout << " ";
    }
    cout << endl;
    */
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    
}
