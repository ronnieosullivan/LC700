class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        int m = words1.size(), n = words2.size();
        if (m != n) return false;
        unordered_set<string> dict;
        for (auto a : pairs) {
            dict.insert(a.first + "#" + a.second);
            dict.insert(a.second + "#" + a.first);
        }
        for (int i = 0; i < n; i++) {
            if (words1[i] == words2[i]) continue;
            if (dict.count(words1[i] + "#" + words2[i]) == 0 
                && dict.count(words2[i] + "#" + words1[i]) == 0) return false;
        }
        return true;
    }
};