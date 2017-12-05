class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> freq, canAppend;
        for (int num : nums) freq[num]++;
        for (int num : nums) {
            if (freq[num] == 0) continue;
            freq[num]--;
            if (canAppend[num] > 0) {
                canAppend[num]--;
                canAppend[num + 1]++;
            }
            else if (freq[num + 1] > 0 && freq[num + 2] > 0) {
                freq[num + 1]--;
                freq[num + 2]--;
                canAppend[num + 3]++;
            }
            else return false;
        }
        return true;
    }
};