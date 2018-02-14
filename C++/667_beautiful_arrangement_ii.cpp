class Solution {
public:
    vector<int> constructArray(int n, int k) {
        int small = 1, large = n;
        vector<int> res(n);
        for (int i = 0; i < k; i++) {
            if (i % 2 == 0) {
                res[i] = small++;
            }
            else res[i] = large--;
        }
        if (k % 2 == 1) { // odd
            for (int i = k; i < n; i++) res[i] = small + i - k;
        }
        else { // even
            for (int i = k; i < n; i++) res[i] = large - i + k;
        }
        return res;
    }
};

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res;
        int i = 1, j = n;
        while (i <= j) {
            if (k > 1) res.push_back(k-- % 2 ? i++ : j--);
            else res.push_back(i++);
        }
        return res;
    }
};