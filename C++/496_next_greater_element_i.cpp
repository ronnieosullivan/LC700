class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> res;
        stack<int> st;
        unordered_map<int, int> m;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (st.empty()) {
                m[nums[i]] = -1;
            }
            else {
                while (!st.empty() && st.top() <= nums[i]) st.pop();
                m[nums[i]] = st.empty() ? -1 : st.top();
            }
            st.push(nums[i]);
        }
        for (auto a : findNums) {
            res.push_back(m[a]);
        }
        return res;
    }
};