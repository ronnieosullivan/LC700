class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int, int>> res;
        sort(people.begin(), people.end(), [](const pair<int, int>& a, const pair<int, int>& b){
            return a.first == b.first ? a.second < b.second : a.first > b.first;
        });
        for (auto& p : people) res.insert(res.begin() + p.second, p);
        return res;
    }
};