class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> res;
        vector<vector<int> > graph(numCourses);
        vector<int> ins(numCourses);
        for (auto& a : prerequisites) {
            graph[a.second].push_back(a.first);
            ++ins[a.first];
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (ins[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            res.push_back(cur);
            for (int a : graph[cur]) {
                if (--ins[a] == 0) q.push(a);
            }
        }
        if (static_cast<int>(res.size()) != numCourses) res.clear();
        return res;
    }
};