class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size(), res = 0;
        vector<int> revIdx(n);
        for (int i = 0; i < n; i++) {
            revIdx[row[i]] = i;
        }
        for (int i = 0; i < n; i += 2) {
            int couple = row[i] % 2 == 0 ? row[i] + 1 : row[i] - 1;
            if (row[i + 1] != couple) {
                res++;
                int coupleIndex = revIdx[couple];
                swap(row[i + 1], row[coupleIndex]);
                swap(revIdx[row[i + 1]], revIdx[row[coupleIndex]]);
            }
        }
        return res;
    }
};