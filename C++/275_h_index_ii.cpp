// Solution 1:
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        for (int i = n - 1; i >= 0; i--) {
            if (citations[i] < n - i) return n - i - 1;
        }
        return n;
    }
};

// Solution 2:
class Solution {
public:
    char findTheDifference(string s, string t) {
        string tmp = s + t;
        return accumulate(begin(tmp), end(tmp), 0, bit_xor<int>());
    }
};