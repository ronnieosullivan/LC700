class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty() || matrix[0].empty()) return res;
        int m = matrix.size(), n = matrix[0].size(), i = 0, j = 0;
        for (int k = 0; k < m * n; k++) {
            res.push_back(matrix[i][j]);
            if ((i + j) % 2 == 0) {
                // top right
                if (j == n - 1) i++;
                else if (i == 0) j++;
                else {
                    i--; j++;
                }
            }
            else {
                // bottom left
                if (i == m - 1) j++;
                else if (j == 0) i++;
                else {
                    i++; j--;
                }
            }
        }
        return res;
    }
};