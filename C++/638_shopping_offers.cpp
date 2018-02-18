// classic
// Solution 1:
class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int res = 0, n = price.size();
        for (int i = 0; i < n; i++) {
            res += price[i] * needs[i];
        }
        for (auto offer : special) {
            bool isValid = true;
            for (int i = 0; i < n; i++) {
                if (needs[i] - offer[i] < 0) isValid = false;
                needs[i] -= offer[i];
            }
            if (isValid) {
                res = min(res, offer.back() + shoppingOffers(price, special, needs));
            }
            for (int i = 0; i < n; i++) {
                needs[i] += offer[i];
            }
        }
        return res;
    }
};