class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int res = 0, cnt = 0;
        vector<int> dict(128);
        int left = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (dict[c] == 0) cnt++;
            dict[c]++;
            while (cnt > k) {
                dict[s[left]]--;
                if (dict[s[left]] == 0) cnt--;
                left++;
            }
            res = max(res, i - left + 1);
        }
        return res;
    }
};