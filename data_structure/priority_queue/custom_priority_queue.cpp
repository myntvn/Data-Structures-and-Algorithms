#include <bits/stdc++.h>
using namespace std;

struct cp {
    bool operator() (vector<int> &v1, vector<int> &v2) {
        if (v1[0] == v2[0]) return v1[1] > v2[1];
        return v1[0] > v2[0];
    }
};

int main() {

    priority_queue<vector<int>, vector<vector<int>>, cp> qu;
    qu.push({9, 20});
    qu.push({7,10});
    qu.push({11,12});
    while (!qu.empty()) {
        auto t = qu.top();
        cout << t[0] << " " << t[1] << endl;
        qu.pop();
    }

    // output
    // 7 10
    // 9 20
    // 11 12

    return 0;
}