class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < B.size(); i++) {
            m[B[i]].push_back(i);
        }
        vector<int> res;
        for (int i = 0; i < A.size(); i++) {
            res.push_back(m[A[i]].back());
            m[A[i]].pop_back();
        }
        return res;
    }
};