class Solution {
public:
    using E = pair<int, int>;
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const E& a, const E& b){
            return a.first == b.first ? a.second > b.second : a.first < b.first;
        });
        vector<int> v;
        for (auto e : envelopes) {
            auto it = lower_bound(v.begin(), v.end(), e.second);
            if (it == v.end()) v.push_back(e.second);
            else *it = e.second;
        }
        return v.size();
    }
};