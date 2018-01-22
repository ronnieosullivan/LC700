class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0, i = 0, n = heights.size();
        stack<int> s;
        heights.push_back(0);
        while (i <= n) {
            if (s.empty() || heights[s.top()] < heights[i]) {
                s.push(i);
                i++;
            }
            else {
                int cur = s.top(); s.pop();
                res = max(res, heights[cur] * (s.empty() ? i : i - s.top() - 1));
            }
        }
        return res;
    }
};