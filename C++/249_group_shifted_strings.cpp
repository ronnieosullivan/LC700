class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> res;
        int index = 0;
        unordered_map<string, int> m;
        for (auto s : strings) {
            string key = getKey(s);
            if (m.count(key) == 0) {
                m[key] = index;
                index++;
                res.push_back({});
            }
            res[m[key]].push_back(s);
        }
        return res;
    }
    string getKey(string s) {
        string res = "";
        int len = s.length();
        for (int i = 1; i < len; i++) {
            int t = s[i] - s[i - 1];
            if (t < 0) t += 26;
            res += to_string(t) + "#";
        }
        return res;
    }
};