class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res = {{}};
        for (auto num : nums) {
            int n = res.size();
            for (int i = 0; i < n; ++i) {
                auto tmp = res[i];
                tmp.push_back(num);
                res.push_back(tmp);
            }
        }
        return res;
    }
};