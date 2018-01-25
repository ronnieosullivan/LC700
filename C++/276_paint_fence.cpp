// Solution 1:张杰
// same[i] = diff[i - 1]
// diff[i] = (same[i - 1] + diff[i - 1]) * (k - 1)
class Solution {
public:
    int numWays(int n, int k) {
        if (n == 0) return 0;
        int same = 0, diff = k;
        for (int i = 1; i < n; ++i) {
            int t = diff;
            diff = (same + diff) * (k - 1);
            same = t;
        }
        return same + diff;
    }
};