class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res = {{}};
        sort(nums.begin(), nums.end());
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            int n = res.size();
            if (i == 0 || nums[i] != nums[i - 1]) cnt = n;
            cout << cnt << endl;
            for (int j = n - cnt; j < n; j++) {
                auto tmp = res[j];
                tmp.push_back(nums[i]);
                res.push_back(tmp);
            }
        }
        return res;
    }
};