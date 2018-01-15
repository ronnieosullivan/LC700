// Solution 1:
// it is important to notice that left edge has to have negative value
// e.g. in case of [[0,2,3],[2,5,3]], we want to make sure that {2, -3}
// comes in before {2, 3}
class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> res, heights;
        multiset<int> s;
        for (auto& building : buildings) {
            heights.push_back({building[0], -building[2]});
            heights.push_back({building[1], building[2]});
        }
        sort(heights.begin(), heights.end());
        s.insert(0);
        int pre = 0;
        for (auto& h : heights) {
            if (h.second < 0) s.insert(-h.second);
            else s.erase(s.find(h.second));
            int t = *(s.rbegin());
            if (t != pre) {
                res.push_back({h.first, t});
                pre = t;
            }
        }
        return res;
    }
};