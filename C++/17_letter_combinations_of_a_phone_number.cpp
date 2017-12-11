class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) return res;
        string dict[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        res.push_back("");
        for (int i = 0; i < digits.size(); ++i) {
            vector<string> tempRes;
            int n = res.size();
            string str = dict[digits[i] - '2'];
            for (int j = 0; j < n; ++j) {
                string tmp = res[j];
                for (int k = 0; k < str.size(); ++k) {
                    tempRes.push_back(tmp + str[k]);
                }
            }
            res = tempRes;
        }
        return res;
    }
};