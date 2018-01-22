class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        vector<double> res(queries.size(), -1.0);
        unordered_map<string, unordered_map<string, double>> m;
        int n = equations.size();
        for (int i = 0; i < n; i++) {
            m[equations[i].first][equations[i].second] = values[i];
            m[equations[i].second][equations[i].first] = 1.0 / values[i];
        }
        for (int i = 0; i < queries.size(); i++) {
            auto query = queries[i];
            if (!m.count(query.first) || !m.count(query.second)) continue;
            else if  (query.first == query.second) res[i] = 1.0;
            else {
                queue<pair<string, double>> q;
                unordered_set<string> used;
                q.push({query.first, 1.0});
                while (!q.empty()) {
                    auto t = q.front(); q.pop();
                    if (t.first == query.second) {
                        res[i] = t.second;
                        break;
                    }
                    used.insert(t.first);
                    for (auto a : m[t.first]) {
                        if (!used.count(a.first)) {
                            a.second *= t.second;
                            q.push(a);
                        }
                    }
                }
            }
        }
        return res;
    }
};