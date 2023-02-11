#include <bits/stdc++.h>
using namespace std;

class MRUQueue {
private:
    vector<int> bit;
    vector<int> arr;
    int end;

    int sum(int idx) {
        int res = 0;
        while (idx > 0) {
            res += bit[idx];
            idx -= (idx & -idx);
        }
        return res;
    }

    void add(int idx, int val) {
        while (idx < bit.size()) {
            bit[idx] += val;
            idx += (idx & -idx);
        }
    }

public:
    MRUQueue(int n) {
        bit = vector<int>(n+2001);
        arr = vector<int>(n+2001);
        end = n+1;
        for (int i = 1; i <= n; ++i) {
            add(i, 1);
            arr[i] = i;
        }
    }
    
    int fetch(int k) {
        int l = 1, r = end;
        while (l < r) {
            int mid = (r+l) / 2;
            if (sum(mid) < k) l = mid+1;
            else r = mid;
        }

        add(l, -1);
        add(end, 1);
        arr[end++] = arr[l];
        return arr[l];
    }
};
