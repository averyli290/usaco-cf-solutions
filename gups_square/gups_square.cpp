#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct Point {
    int x;
    int y;
};

struct Line {
    int a;
    int b;
    int c;
};

int hash_point(const Point& p) {
    return p.x + 1000000007 * p.y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;
    vector<Point> points;
    //unordered_set<Point> point_set;
    unordered_set<int> point_set;


    int x, y;

    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        Point new_point = {x, y};
        points.push_back(new_point);
        point_set.insert(hash_point(points[i]));
    }

    int max_area = 0;

    for(int i = 0; i < n; i++) {
        Point a = points[i];
        for(int j = i + 1; j < n; j++) {
            cout << max_area << endl;
            Point b = points[j];
            Point midpoint = {(a.x + b.x) / 2, (a.y + b.y) / 2};
            Point diag1 = {midpoint.x + (a.y - b.y) / 2, midpoint.y + (b.x - a.x) / 2};
            Point diag2 = {midpoint.x - (a.y - b.y) / 2, midpoint.y - (b.x - a.x) / 2};
            int diag1_hash_point = hash_point(diag1);
            int diag2_hash_point = hash_point(diag2);
            if (point_set.find(diag1_hash_point) != point_set.end() && point_set.find(diag2_hash_point) != point_set.end()) {
                int area = (a.x - diag1.x) * (a.x - diag1.x);
                max_area = max(max_area, area);
            }
        }
    }
    
    cout << max_area << endl;

}
