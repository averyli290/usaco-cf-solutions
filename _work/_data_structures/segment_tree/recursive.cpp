// Source: https://usaco.guide/gold/PURS?lang=cpp#dynamic-range-minimum-queries

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

/** A data structure that can answer point update & range min queries. */
template <class T> class SegmentTree {
  private:
    const T DEFAULT = std::numeric_limits<T>().max();

    int len;
    vector<T> segtree;  // index 0 is not in use

    T combine(const T &a, const T &b) {
        return min(a, b);
    }

    void build(const vector<T> &arr, int at, int at_left, int at_right) {
        if (at_left == at_right) {
            segtree[at] = arr[at_left];
            return;
        }
        int mid = (at_left + at_right) / 2;
        build(arr, 2 * at, at_left, mid);
        build(arr, 2 * at + 1, mid + 1, at_right);
        segtree[at] = combine(segtree[2 * at], segtree[2 * at + 1]);
    }

    void set(int ind, T val, int at, int at_left, int at_right) {
        if (at_left == at_right) {
            segtree[at] = val;
            return;
        }
        int mid = (at_left + at_right) / 2;
        if (ind <= mid) {
            set(ind, val, 2 * at, at_left, mid);
        } else {
            set(ind, val, 2 * at + 1, mid + 1, at_right);
        }
        segtree[at] = combine(segtree[2 * at], segtree[2 * at + 1]);
    }

    T range_query(int start, int end, int at, int at_left, int at_right) {
        if (at_right < start || end < at_left) { return DEFAULT; }
        if (start <= at_left && at_right <= end) { return segtree[at]; }
        int mid = (at_left + at_right) / 2;
        T left_res = range_query(start, end, 2 * at, at_left, mid);
        T right_res = range_query(start, end, 2 * at + 1, mid + 1, at_right);
        return combine(left_res, right_res);
    }

  public:
    SegmentTree(int len) : len(len) { segtree = vector<T>(len * 4, DEFAULT); };

    SegmentTree(const vector<T> &arr) : len(arr.size()) {
        segtree = vector<T>(len * 4, DEFAULT);
        build(arr, 1, 0, len - 1);
    }

    /** Sets the value at ind to val. */
    void set(int ind, T val) { set(ind, val, 1, 0, len - 1); }

    /** @return the minimum element in the range [start, end] */
    T range_query(int start, int end) { return range_query(start, end, 1, 0, len - 1); }
};

int main() {
    int arr_len;
    int query_num;
    cin >> arr_len >> query_num;
    vector<long long> arr(arr_len);
    for (long long &i : arr) { cin >> i; }

    SegmentTree<long long> segtree(arr);
    for (int q = 0; q < query_num; q++) {
        int type;
        cin >> type;
        if (type == 1) {
            int ind, val;
            cin >> ind >> val;
            segtree.set(ind - 1, val);
        } else if (type == 2) {
            int start, end;
            cin >> start >> end;
            cout << segtree.range_query(start - 1, end - 1) << '\n';
        }
    }
}