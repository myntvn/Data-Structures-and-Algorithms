#include "bits/stdc++.h"
using namespace std;

struct cmp {
    bool operator() (const vector<int> &a, const vector<int> &b) {
        return a[0] > b[0];
    }
};

class DijikstraSolution {
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

int dir[5] = {0, 1, 0, -1, 0};
class BinarySearchSolution {
public:
    int m, n;
    bool dfs(vector<vector<int>> &heights, int r, int c, int threshold, vector<vector<bool>> &visited) {
        if (r == m-1 && c == n-1) return true;

        visited[r][c] = true;
        for (int i = 0; i < 4; ++i) {
            int newR = r + dir[i], newC = c + dir[i+1];
            if (newR < 0 || newR == m || newC < 0 || newC == n || visited[newR][newC]) continue;
            if(abs(heights[r][c] - heights[newR][newC]) <= threshold &&
               dfs(heights, newR, newC, threshold, visited)) return true;
        }
        return false;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        int left = 0, right = 1e6;
        int res = right;
        while (left <= right) {
            int mid = (right + left) / 2;
            vector<vector<bool>> visited(m, vector<bool>(n));
            if (dfs(heights, 0, 0, mid, visited)) {
                res = mid;
                right = mid-1;
            } else {
                left = mid + 1;
            }
        }

        return res;
    }
};

int main() {
    vector<vector<int>> heights;
    heights.push_back({1, 2, 2});
    heights.push_back({3, 8, 2});
    heights.push_back({5, 3, 5});
    DijikstraSolution s1;
    BinarySearchSolution s2;
    cout << "Dijikstra: " << s1.minimumEffortPath(heights) << endl;
    cout << "Binary search:" << s2.minimumEffortPath(heights) << endl;

    return 0;
}
