const int MAXN = 1e5;

struct DSU {
    vector<int> parent;
    vector<int> size;

    DSU() {
        parent = vector<int>(MAXN);
        size = vector<int>(MAXN, 0);
    }
    DSU(int n) {
        parent = vector<int>(n + 1);
        size = vector<int>(n + 1, 0);
    }
    void make_set(int v) {
        parent[v] = v;
        size[v] = 1;
    }
    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};