#include <algorithm>
#include <iostream>
#include <cassert>

template <class T>
class SegmentTree {
   private:
    size_t size;
    T* tree;

    int get_first(int node, size_t left, size_t right, size_t l, size_t r, double x) {
        if (r < left || right < l)
            return -1;

        if (l <= left && right <= r) {
            if (tree[node] < x)
                return -1;

            while (left != right) {
                int mid = left + (right - left) / 2;
                if (x <= tree[2 * node]) {
                    node = 2 * node;
                    right = mid;
                } else {
                    node = 2 * node + 1;
                    left = mid + 1;
                }
            }

            return left;
        }

        int mid = left + (right - left) / 2;
        int result = get_first(2 * node, left, mid, l, r, x);

        if (result != -1)
            return result;

        return get_first(2 * node + 1, mid + 1, right, l, r, x);
    }

   public:
    SegmentTree(size_t size) : size(size) {
        tree = new T[4 * size];
    }

    SegmentTree(T* array, size_t size) : size(size) {
        tree = new T[4 * size];
        build(array, 1, 0, size - 1);
    }

    ~SegmentTree() {
        delete[] tree;
    }

    void build(T* array, size_t node, size_t left, size_t right) {
        if (left == right) {
            tree[node] = array[left];
        } else {
            size_t mid = left + (right - left) / 2;
            build(array, 2 * node, left, mid);
            build(array, 2 * node + 1, mid + 1, right);
            tree[node] = std::max({tree[2 * node], tree[2 * node + 1]});
        }
    }

    int get_first(int l, int r, double x) {
        return get_first(1, 0, size - 1, l, r, x);
    }
};

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    assert(2 <= n && n <= 1e6);
    assert(2 <= q && q <= 1e6);

    int* array = new int[n];

    for (int i = 0; i < n; i++)
        scanf("%d", array + i);

    SegmentTree<int> tree(array, n);

    for (int i = 0; i < q; i++) {
        int x, a;
        scanf("%d%d", &x, &a);

        double target = array[x] * (100 + a) / 100.;
        int position = tree.get_first(x, n - 1, target);

        if (position != -1)
            printf("%d\n", position - x);
        else
            printf("-1\n");
    }

    return 0;
}