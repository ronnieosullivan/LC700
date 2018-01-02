class Solution {
public:
    string nextClosestTime(string time) {
        unordered_set<char> s;
        for (char c : time) s.insert(c);
        int hh = stoi(time.substr(0, 2));
        int mm = stoi(time.substr(3));
        for (int t = hh * 60 + mm + 1; t < hh * 60 + mm + 1440; t++) {
            int h = (t % 1440) / 60;
            int m = (t % 1440) % 60;
            string hs = h == 0 ? "00" : (h > 9 ? to_string(h) : "0" + to_string(h));
            string ms = m == 0 ? "00" : (m > 9 ? to_string(m) : "0" + to_string(m));
            string ts = hs + ":" + ms;
            bool valid = true;
            for (auto c : ts) {
                if (!s.count(c)) {
                    valid = false;
                    break;
                }
            }
            if (valid) return hs + ":" + ms;
        }
        return time;
    }
};