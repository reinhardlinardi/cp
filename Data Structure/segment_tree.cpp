#include <iostream>
#include <vector>

using namespace std;

class SegmentTree {
private:
    int n;
    vector<int> arr;
    vector<int> segment_tree;
    vector<int> lazy;

    int left_child(int parent) { return (parent << 1) + 1; }

    int right_child(int parent) { return (parent << 1) + 2; }

    void build(int parent, int left, int right) {
        if (left > right)
            return;

        if (left == right) {
            segment_tree[parent] = arr[left];

            return;
        }

        int mid = (left + right) / 2;
        build(left_child(parent), left, mid);
        build(right_child(parent), mid + 1, right);

        segment_tree[parent] = segment_tree[left_child(parent)] +
                               segment_tree[right_child(parent)];
    }

    int query(int parent, int left, int right, int i, int j) {
        if (lazy[parent] != 0) {
            segment_tree[parent] += (right - left + 1) * lazy[parent];

            if (left != right) {
                lazy[left_child(parent)] += lazy[parent];
                lazy[right_child(parent)] += lazy[parent];
            }

            lazy[parent] = 0;
        }

        if (left > right || left > j || right < i)
            return 0;

        if (left >= i && right <= j) {
            return segment_tree[parent];
        }

        int mid = (left + right) / 2;
        return query(left_child(parent), left, mid, i, j) +
               query(right_child(parent), mid + 1, right, i, j);
    }

    void update_range(int parent, int left, int right, int i, int j, int y) {
        if (lazy[parent] != 0) {
            segment_tree[parent] += (right - left + 1) * lazy[parent];

            if (left != right) {
                lazy[left_child(parent)] += lazy[parent];
                lazy[right_child(parent)] += lazy[parent];
            }

            lazy[parent] = 0;
        }

        if (left > right || left > j || right < i)
            return;

        if (left >= i && right <= j) {
            segment_tree[parent] += (right - left + 1) * y;

            if (left != right) {
                lazy[left_child(parent)] += y;
                lazy[right_child(parent)] += y;
            }

            return;
        }

        int mid = (left + right) / 2;
        update_range(left_child(parent), left, mid, i, j, y);
        update_range(right_child(parent), mid + 1, right, i, j, y);

        segment_tree[parent] = segment_tree[left_child(parent)] +
                               segment_tree[right_child(parent)];
    }

public:
    SegmentTree(int _n, vector<int> &_arr) {
        n = _n;
        arr = _arr;

        segment_tree.assign(4 * n, 0);
        build(0, 0, n - 1);

        lazy.assign(4 * n, 0);
    }

    int query(int i, int j) { return query(0, 0, n - 1, i, j); }

    void update_range(int i, int j, int y) {
        update_range(0, 0, n - 1, i, j, y);
    }
};

int main() {
    int n = 7;
    vector<int> arr = {18, 17, 13, 19, 15, 11, 20};
    SegmentTree st(n, arr);

    cout << "query(1, 3) = " << st.query(1, 3) << '\n';

    st.update_range(2, 4, 2);

    cout << "query(4, 6) = " << st.query(3, 6) << '\n';
}
