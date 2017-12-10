class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        int m = words1.size(), n = words2.size();
        if (m != n) return false;
        unordered_map<string, string> roots;
        for (auto a : pairs) {
            string root1 = getRoot(a.first, roots);
            string root2 = getRoot(a.second, roots);
            if (root1 != root2) {
                roots[root1] = root2;
            }
        }
        for (int i = 0; i < n; i++) {
            if (getRoot(words1[i], roots) != getRoot(words2[i], roots)) return false;
        }
        return true;
    }
    string getRoot(string s, unordered_map<string, string>& roots) {
        while (!roots[s].empty()) {
            s = roots[s];
        }
        return s;
    }
};