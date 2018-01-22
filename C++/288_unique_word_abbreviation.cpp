class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> dictionary) {
        for (auto s : dictionary) {
            string t = getAbbr(s);
            auto it = m.find(t);
            if (it != m.end() && it->second != s) it->second = "";
            else m[t] = s;
        }
    }
    bool isUnique(string word) {
        string t = getAbbr(word);
        auto it = m.find(t);
        return it == m.end() || it->second == word;
    }
    string getAbbr(const string& s) {
        if (s.length() <= 2) return s;
        else return s[0] + to_string(s.length() - 2) + s[s.length() - 1];
    }
private:
    unordered_map<string, string> m;
};