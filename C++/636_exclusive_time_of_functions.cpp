class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n);
        stack<int> s;
        int pre = 0;
        for (auto& log : logs) {
            istringstream iss(log);
            string t;
            getline(iss, t, ':');
            int proc = stoi(t);
            getline(iss, t, ':');
            string type = t;
            getline(iss, t, ':');
            int time = stoi(t);
            if (type == "start") {
                if (!s.empty()) res[s.top()] += time - pre;
                s.push(proc);
                pre = time;
            }
            else {
                res[s.top()] += time - pre + 1;
                s.pop();
                pre = time + 1;
            }
        }
        return res;
    }
};