#include <bits/stdc++.h>

using namespace std;

class FenwickTree {
private:
    vector<int> arr;

public:
    FenwickTree(int n) {
        arr = vector<int>(n+1, 0);
    }

    int sum(int idx) {
        int sum = 0;
        ++idx;
        while (idx > 0) {
            sum += arr[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }

    void add(int idx, int val) {
        ++idx;
        while (idx < arr.size()) {
            arr[idx] += val;
            idx += (idx & -idx);
        }
    }
};

int main() {
    int n = 5;
    FenwickTree tree(n);
    tree.add(0, 1);
    cout << tree.sum(n-1) << endl;

    return 0;
}
