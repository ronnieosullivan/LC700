// Solution 1:
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int n = heaters.size(), j = 0, res = 0;
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        for (int i = 0; i < houses.size(); ++i) {
            int cur = houses[i];
            while (j < n - 1 && abs(heaters[j + 1] - cur) <= abs(heaters[j] - cur)) {
                ++j;
            }
            res = max(res, abs(heaters[j] - cur));
        }
        return res;
    }
};

// Solution 2:
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int res = 0;
        sort(heaters.begin(), heaters.end());
        for (int house : houses) {
            auto pos = lower_bound(heaters.begin(), heaters.end(), house);
            int dist1 = (pos == heaters.end()) ? INT_MAX : *pos - house;
            int dist2 = (pos == heaters.begin()) ? INT_MAX : house - *(--pos);
            res = max(res, min(dist1, dist2));
        }
        return res;
    }
};