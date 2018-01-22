// Solution 1:
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int i = 0, j = n - 1, h = 0, res = 0;
        while (i < j) {
            h = max(h, min(height[i], height[j]));
            if (height[i] < height[j]) {
                res += h - height[i];
                i++;
            }
            else {
                res += h - height[j];
                j--;
            }
        }
        return res;
    }
};

// Solution 2:
// stack solution
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int i = 0, res = 0, n = height.size();
        while (i < n) {
            if (st.empty() || height[i] <= height[st.top()]) {
                st.push(i);
                i++;
            } else {
                int t = st.top(); st.pop();
                if (st.empty()) continue;
                res += (min(height[i], height[st.top()]) - height[t]) * (i - st.top() - 1);
            }
        }
        return res;
    }
};