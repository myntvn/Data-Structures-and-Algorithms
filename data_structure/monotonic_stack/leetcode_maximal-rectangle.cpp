#include <bits/stdc++.h>
using namespace std;

int maximalRectangle(vector<vector<char>>& A) {
    int m = A.size();
    if (m == 0) return 0;
    int n = A[0].size()+1;
    int res = 0;
    vector<int> h(n);
    for (int i = 0; i < m; ++i) {
        stack<int> st;
        for (int j = 0; j < n; ++j) {
            if (j == n-1 || A[i][j] == '0') h[j] = 0;
            else h[j]++;
            while (!st.empty() && h[st.top()] > h[j]) {
                int height = h[st.top()]; st.pop();
                int left = st.empty() ? -1 : st.top();
                res = max(res, height * (j-left-1));
            }
            st.push(j);
        }
    }
    return res;
}