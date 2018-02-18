class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();
        vector<int> v(k), res;
        res.push_back(1);
        for (int i = 0; i < n; i++) {
            int mn = INT_MAX;
            for (int j = 0; j < k; j++) {
                mn = min(mn, res[v[j]] * primes[j]);
            }
            for (int j = 0; j < k; j++) {
                if (res[v[j]] * primes[j] == mn) v[j]++;
            }
            res.push_back(mn);
        }
        return res[n - 1];
    }
};