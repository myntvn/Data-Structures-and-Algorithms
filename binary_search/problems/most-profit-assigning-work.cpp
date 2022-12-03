// https://leetcode.com/problems/most-profit-assigning-work/

struct cp {
    bool operator() (const pair<int,int> &a, const pair<int,int> &b) {
        return a.first > b.first;
    }
} compare;

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> arr;
        for (int i = 0; i < difficulty.size(); ++i) arr.push_back({difficulty[i], i});
        
        sort(arr.begin(), arr.end(), compare);
        
        sort(worker.begin(), worker.end());
        int res = 0;
        int mx = 0;
        auto end = arr.end();
        for (int &w : worker) {
            auto p = lower_bound(begin(arr), end, w, [&](const pair<int,int> &a, const int &b) {
                return a.first > b;
            });
            if (p != arr.end()) {
                int i = p - arr.begin();
                int j = end - arr.begin();

                for (int k = i; k < j; ++k) {
                    mx = max(mx, profit[arr[k].second]);
                }
                res += mx;
                end = p;
            }   
        }
        
        return res;
    }
};