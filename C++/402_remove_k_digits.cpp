class Solution {
public:
    string removeKdigits(string num, int k) {
        for (int i = 0; i < k; i++) {
            if (num.empty()) return "0";
            int j = 0, len = num.size();
            while (j < len - 1 && num[j] <= num[j + 1]) {
                j++;
            }
            num.erase(j, 1);
            while (!num.empty() && num.front() == '0') num.erase(0, 1);
        }
        return num.empty() ? "0" : num;
    }
};