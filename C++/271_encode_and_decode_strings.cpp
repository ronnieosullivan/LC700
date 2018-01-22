class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        ostringstream oss;
        for (auto& str : strs) {
            oss << str.length() << " " << str << " ";
        }
        return oss.str();
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while (i < s.length()) {
            int index = s.find(' ', i);
            int len = stoi(s.substr(i, index - i));
            res.push_back(s.substr(index + 1, len));
            i = index + len + 2;
        }
        return res;
    }
};