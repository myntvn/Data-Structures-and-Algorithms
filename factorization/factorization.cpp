#include <bits/stdc++.h>
using namespace std;

// return list of factors except 1
vector<int> pfact(int n) {
    vector<int> res;
    for (int i = 2; i*i <= n; ++i) {
        while (n%i == 0) {
            n /= i;
            res.push_back(i);
        }
    }
    if (n != 1) res.push_back(n);
    return res;
}
