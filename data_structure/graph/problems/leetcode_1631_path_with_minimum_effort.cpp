#include "bits/stdc++.h"
using namespace std;

struct cmp {
    bool operator() (const vector<int> &a, const vector<int> &b) {
        return a[0] > b[0];
    }
};

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
        cost[0][0] = 0;
        
        priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
        pq.push({0, 0, 0});
        
        int dir[] = {0, 1, 0, -1, 0};
        while (!pq.empty()) {
            auto top = pq.top(); pq.pop();
            int dis = top[0], r = top[1], c = top[2];
            if (r == m-1 && c == n-1) return cost[r][c];
            for (int i = 0; i < 4; ++i) {
                int newR = r + dir[i], newC = c + dir[i+1];
                if (newR < 0 || newR == m || newC < 0 || newC == n) continue;
                int newDis = max(dis, abs(heights[r][c] - heights[newR][newC]));
                if (newDis < cost[newR][newC]) {
                    cost[newR][newC] = newDis;
                    pq.push({newDis, newR, newC});
                }
            }
        }
        return 0;
    }
};

int main() {
    vector<vector<int>> heights;
    heights.push_back({1, 2, 2});
    heights.push_back({3, 8, 2});
    heights.push_back({5, 3, 5});
    Solution s;
    cout << "Minimum effort is: " << s.minimumEffortPath(heights) << endl;

    return 0;
}
