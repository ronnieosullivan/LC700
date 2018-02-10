class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) {
        int n = stations.size();
        double left = 0.0, right = stations[n - 1] - stations[0];
        while (left + 1e-6 < right) {
            double mid = (left + right) / 2.0;
            int count = 0;
            for (int i = 1; i < n; i++) {
                count += ceil((stations[i] - stations[i - 1]) / mid) - 1;
            }
            if (count > K) left = mid;
            else right = mid;
        }
        return right;
    }
};