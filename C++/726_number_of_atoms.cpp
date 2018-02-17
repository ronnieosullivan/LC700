// Solution 1:
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

// Solution 2:
// stack
class Solution {
public:
    string countOfAtoms(string formula) {
        stack<map<string, int>> st;
        st.push({});
        for (int i = 0; i < formula.size(); ++i) {
            if (formula[i] == '(') {
                st.push({});
            }
            else if (formula[i] == ')') {
                int cnt = 0;
                while (i + 1 < formula.size() && formula[i + 1] >= '0' && formula[i + 1] <= '9') {
                    cnt = cnt * 10 + formula[i + 1] - '0';
                    i++;
                }
                auto m = st.top(); st.pop();
                for (auto& a : m) {
                    st.top()[a.first] += a.second * (cnt == 0 ? 1 : cnt);
                }
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
                st.top()[tmp] += (cnt == 0 ? 1 : cnt);
            }
        }
        string res("");
        for (auto& a : st.top()) {
            res += a.first + (a.second == 1 ? "" : to_string(a.second));
        }
        return res;
    }
};

// Solution 3:
// a more general solution
class Solution {
public:
    string countOfAtoms(string formula) {
        map<string, int> m;
        unordered_map<int, int> b;
        stack<int> st;
        for (int i = 0; i < formula.size(); i++) {
            if (formula[i] == '(') st.push(i);
            else if (formula[i] == ')') {
                b[st.top()] = i; st.pop();
            }
        }
        helper(formula, 0, formula.size(), m, b);
        string res("");
        for (auto& a : m) {
            res += a.first + (a.second == 1 ? "" : to_string(a.second));
        }
        return res;
    }
    void helper(string& formula, int start, int end, map<string, int>& m, unordered_map<int, int>& b) {
        for (int i = start; i < end; i++) {
            if (formula[i] == '(') {
                map<string, int> tmp;
                helper(formula, i + 1, b[i], tmp, b);
                i = b[i] + 1;
                int cnt = 0;
                while (i < end && formula[i] >= '0' && formula[i] <= '9') {
                    cnt = cnt * 10 + formula[i] - '0';
                    i++;
                }
                i--;
                for (auto& a : tmp) {
                    m[a.first] += a.second * (cnt == 0 ? 1 : cnt);
                }
            }
            else {
                string t = formula.substr(i, 1);
                if (i + 1 < end && formula[i + 1] >= 'a' && formula[i + 1] <= 'z') {
                    t.push_back(formula[i + 1]);
                    i++;
                }
                int cnt = 0;
                while (i + 1 < end && formula[i + 1] >= '0' && formula[i + 1] <= '9') {
                    cnt = cnt * 10 + formula[i + 1] - '0';
                    i++;
                }
                m[t] += (cnt == 0 ? 1 : cnt);
            }
        }
    }
};