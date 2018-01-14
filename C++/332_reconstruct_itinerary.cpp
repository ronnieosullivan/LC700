// Solution 1:
class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> res;
        unordered_map<string, multiset<string>> m;
        for (auto& ticket : tickets) {
            m[ticket.first].insert(ticket.second);
        }
        dfs(m, "JFK", res);
        return vector<string>(res.rbegin(), res.rend());
    }
    void dfs(unordered_map<string, multiset<string>>& m, string s, vector<string>& res) {
        while (!m[s].empty()) {
            string t = *m[s].begin();
            m[s].erase(m[s].begin());
            dfs(m, t, res);
        }
        res.push_back(s);
    }
};

// Solution 2:
class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> res;
        stack<string> st{{"JFK"}};
        unordered_map<string, multiset<string>> m;
        for (auto t : tickets) {
            m[t.first].insert(t.second);
        }
        while (!st.empty()) {
            string t = st.top(); 
            if (m[t].empty()) {
                res.push_back(t);
                st.pop();
            } else {
                st.push(*m[t].begin());
                m[t].erase(m[t].begin());
            }
        }
        return vector<string>(res.rbegin(), res.rend());
    }
};