class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> m;
        int mx = 0, mxCnt = 0;
        for (char task : tasks) {
            m[task]++;
            if (m[task] > mx) {
                mx = m[task];
                mxCnt = 1;
            }
            else if (m[task] == mx) {
                mxCnt++;
            }
        }
        return max((int)(tasks.size()), (mx - 1) * (n + 1) + mxCnt);
    }
};