class Solution {
public:
    string countOfAtoms(string formula) {
        int level = 0;
        vector<map<string, int>> v {{}};
        for (int i = 0; i < formula.size(); ++i) {
            if (formula[i] == '(') {
                level++;
                if (level >= v.size()) v.push_back({});
            }
            else if (formula[i] == ')') {
                int cnt = 0;
                while (i + 1 < formula.size() && formula[i + 1] >= '0' && formula[i + 1] <= '9') {
                    cnt = cnt * 10 + formula[i + 1] - '0';
                    i++;
                }
                for (auto& a : v[level]) {
                    v[level - 1][a.first] += a.second * (cnt == 0 ? 1 : cnt);
                }
                v.pop_back();
                level--;
            }
            else { // must be element + number format
                string tmp = formula.substr(i, 1);
                if (i + 1 < formula.size() && formula[i + 1] >= 'a' && formula[i + 1] <= 'z') {
                    tmp.push_back(formula[i + 1]);
                    i++;
                }
                int cnt = 0;
                while (i + 1 < formula.size() && formula[i + 1] >= '0' && formula[i + 1] <= '9') {
                    cnt = cnt * 10 + formula[i + 1] - '0';
                    i++;
                }
                v[level][tmp] += (cnt == 0 ? 1 : cnt);
            }
        }
        string res("");
        for (auto& a : v[0]) {
            res += a.first + (a.second == 1 ? "" : to_string(a.second));
        }
        return res;
    }
};