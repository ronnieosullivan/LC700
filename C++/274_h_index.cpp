class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end(), greater<int>());
        for (int i = 0; i < n; i++) {
            if (citations[i] <= i) return i;
        }
        return n;
    }
};