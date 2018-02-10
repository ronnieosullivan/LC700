class Solution {
public:
    bool canTransform(string start, string end) {
        if (start.size() != end.size()) return false;
        int L = 0, R = 0;
        for (int i = 0; i < start.size(); i++) {
            if (start[i] == 'R') R++;
            else if (start[i] == 'L') L++;
            if (end[i] == 'R') R--;
            else if (end[i] == 'L') L--;
            if (R < 0 || L > 0) return false;
            if (R > 0 && L < 0) return false;
        }
        return L == 0 && R == 0;
    }
};