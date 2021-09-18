#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& H) {
    H.push_back(0);
    stack<int> st;
    int res = 0;
    for (int i = 0; i < H.size(); ++i) {
        while (!st.empty() && H[st.top()] > H[i]) {
            int h = H[st.top()]; st.pop();
            int l = st.empty() ? -1 : st.top();
            res = max(res, h * (i-l-1));
        }
        st.push(i);
    }
    
    return res;
}