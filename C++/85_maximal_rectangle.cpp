// Solution 1:
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int res = 0, m = matrix.size(), n = matrix[0].size();
        vector<int> heights(n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                heights[j] = matrix[i][j] == '0' ? 0 : (1 + heights[j]);
            }
            res = max(res, largestRectangleArea(heights));
        }
        return res;
    }
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
        heights.pop_back();
        return res;
    }
};

// Solution 2:
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int res = 0, m = matrix.size(), n = matrix[0].size();
        vector<int> height(n, 0), left(n, 0), right(n, n);
        for (int i = 0; i < m; ++i) {
            int cur_left = 0, cur_right = n;
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') ++height[j];
                else height[j] = 0;
            }
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') left[j] = max(left[j], cur_left);
                else {left[j] = 0; cur_left = j + 1;}
            }
            for (int j = n - 1; j >= 0; --j) {
                if (matrix[i][j] == '1') right[j] = min(right[j], cur_right);
                else {right[j] = n; cur_right = j;}
            }
            for (int j = 0; j < n; ++j) {
                res = max(res, (right[j] - left[j]) * height[j]);
            }
        }
        return res;
    }
};