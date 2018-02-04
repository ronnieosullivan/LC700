class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int m = 0, n = 0, cm = 0, cn = 0;
        for (auto num : nums) {
            if (num == m) cm++;
            else if (num == n) cn++;
            else if (cm == 0) { m = num; cm = 1; }
            else if (cn == 0) { n = num; cn = 1; }
            else {
                cm--; cn--;
            }
        }
        cm = cn = 0;
        for (auto num : nums) {
            if (num == m) cm++;
            else if (num == n) cn++;
        }
        if (cm > nums.size() / 3) res.push_back(m);
        if (cn > nums.size() / 3) res.push_back(n);
        return res;
    }
};