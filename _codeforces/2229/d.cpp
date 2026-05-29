/*
Problem link:
*/

#include <bits/stdc++.h>

using namespace std;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define debug(x) cout << #x << " is " << x << endl;
const long long INF = 1e18;

/*
take indices, can calc off of that

*/

struct tiii {
    int x;
    int y;
    int z;
};


void solve() {
    int n; cin >> n;
    vi a(n), b(n);
    // vector<tiii> ab(n);
    vector<pii> ab(n);
    vector<pii> prefmin(n);
    vector<pii> suffmin(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    // for(int i = 0; i < n; i++) ab[i] = tiii{a[i], b[i], i};
    for(int i = 0; i < n; i++) ab[i] = pii{a[i], b[i]};
    prefmin[0] = ab[0];
    suffmin[n - 1] = ab[n - 1];
    for(int i = 1; i < n; i++) {
        vi temp = vi({prefmin[i - 1].first, prefmin[i - 1].second, a[i], b[i]});
        sort(all(temp));
        prefmin[i] = pii{temp[0], temp[1]};
    }
    for(int i = n - 2; i >= 0; i--) {
        vi temp = vi({suffmin[i + 1].first, suffmin[i + 1].second, a[i], b[i]});
        sort(all(temp));
        suffmin[i] = pii{temp[0], temp[1]};
    }
    // sort(all(a));
    // sort(all(b));
    function<pii(pii, pii)> calc = [&](pii x, pii y) {
        vi temp = vi({x.first, x.second, y.first, y.second});
        sort(all(temp));
        return pii{temp[1], temp[2]};
    };
    if (n == 1) {
        cout << min(a[0], b[0]) << endl;
        return;
    } 
    if (n == 2) {
        pii t = calc(ab[0], ab[1]);
        cout << min(t.first, t.second) << endl;
        return;
    }

    int ans = 0;

    pii temp1 = calc(ab[0], suffmin[1]);
    ans = max(ans, min(temp1.first, temp1.second));
    temp1 = calc(ab[n - 1], prefmin[n - 2]);
    ans = max(ans, min(temp1.first, temp1.second));
    debug(ans);

    for(int i = 1; i < n - 1; i++) {
        debug(i);
        cout << prefmin[i - 1].first << " " << prefmin[i - 1].second << endl;
        cout << ab[i].first << " " << ab[i].second << endl;
        cout << suffmin[i + 1].first << " " << suffmin[i + 1].second << endl;
        pii first = prefmin[i - 1];
        pii last = suffmin[i + 1];
        pii t1 = calc(calc(first, ab[i]), last);
        pii t2 = calc(calc(last, ab[i]), first);
        int ans1 = min(t1.first, t1.second);
        int ans2 = min(t2.first, t2.second);
        ans = max(max(ans1, ans2), ans);
    }
    cout << ans << endl;


    // auto cmp = [&](tiii x, tiii y) {
    //     if (x.x < y.x) return 1;
    //     if (x.y < y.y) return 1;
    //     return 0;
    // };
    // sort(all(ab), cmp);

    // for(int i = 0 ; i < n; i++) {
    //     cout << ab[i].x << " ";
    // }
    // cout << endl;
    // for(int i = 0 ; i < n; i++) {
    //     cout << ab[i].y << " ";
    // }
    // cout << endl;

    // function<tiii(tiii, tiii)> calc = [&](tiii x, tiii y) {
    //     vi temp = vi({x.x, x.y, y.x , y.y });
    //     sort(all(temp));
    //     return tiii{temp[1], temp[2], 0};
    // };
    // if (n == 1) {
    //     cout << min(a[0], b[0]) << endl;
    //     return;
    // }
    // if (n == 2) {
    //     tiii t = calc(ab[0], ab[1]);
    //     cout << min(t.x, t.y) << endl;
    // }
    // int ans = 0;
    // for(int i = 0; i < n - 2; i++) {
    //     tiii t1 = ab[i];
    //     tiii t2 = ab[i + 1];
    //     tiii t3 = ab[i + 2];
    //     vector<tiii> ts({t1, t2, t3});
    //     sort(all(ts), [&] (tiii x, tiii y) {return x.z < y.z;});
    //     tiii t4 = calc(calc(ts[0], ts[1]), ts[2]);
    //     tiii t5 = calc(calc(ts[2],ts[1]), ts[0]);
    //     int ans1 = min(t4.x, t4.y);
    //     int ans2 = min(t5.x, t5.y);
    //     ans = max(max(ans1, ans2), ans);
    //     // pii t1 = calc(calc(ab[i], ab[i + 1]), ab[i + 2]);
    //     // pii t2 = calc(calc(ab[i + 2], ab[i + 1]), ab[i]);
    //     // int ans1 = min(t1.first, t1.second);
    //     // int ans2 = min(t2.first, t2.second);
    //     // ans = max(max(ans1, ans2), ans);
    // }
    // cout << ans << endl;
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
