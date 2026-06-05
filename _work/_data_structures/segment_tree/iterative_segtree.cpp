// Source: https://usaco.guide/gold/PURS?lang=cpp#iterative-implementation

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

template <class T> class MinSegmentTree {
  private:
    const T DEFAULT = std::numeric_limits<T>().max();

    vector<T> segtree;
    int len;

  public:
    MinSegmentTree(int len) : len(len), segtree(len * 2, DEFAULT) {}

    void set(int ind, T val) {
        ind += len;
        segtree[ind] = val;
        for (; ind > 1; ind /= 2) {
            segtree[ind / 2] = std::min(segtree[ind], segtree[ind ^ 1]);
        }
    }

    T range_min(int start, int end) {
        T min = DEFAULT;
        for (start += len, end += len; start < end; start /= 2, end /= 2) {
            if (start % 2 == 1) { min = std::min(min, segtree[start++]); }
            if (end % 2 == 1) { min = std::min(min, segtree[--end]); }
        }
        return min;
    }
};

int main() {
    int arr_len;
    int query_num;
    std::cin >> arr_len >> query_num;

    MinSegmentTree<int> segtree(arr_len);
    for (int i = 0; i < arr_len; i++) {
        int n;
        std::cin >> n;
        segtree.set(i, n);
    }

    for (int q = 0; q < query_num; q++) {
        int type, arg1, arg2;
        std::cin >> type >> arg1 >> arg2;
        if (type == 1) {
            segtree.set(arg1 - 1, arg2);
        } else if (type == 2) {
            cout << segtree.range_min(arg1 - 1, arg2) << '\n';
        }
    }
}