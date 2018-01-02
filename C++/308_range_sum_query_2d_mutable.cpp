class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        _nums.resize(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        _bits.resize(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                update(i, j, matrix[i][j]);
            }
        }
    }
    
    void update(int row, int col, int val) {
        int diff = val - _nums[row + 1][col + 1];
        for (int i = row + 1; i < _nums.size(); i += i&-i) {
            for (int j = col + 1; j < _nums[i].size(); j += j&-j) {
                _bits[i][j] += diff;
            }
        }
        _nums[row + 1][col + 1] = val;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return getSum(row2, col2) - getSum(row1 - 1, col2) - getSum(row2, col1 - 1) + getSum(row1 - 1, col1 - 1);
    }
    
    int getSum(int row, int col) {
        int res = 0;
        for (int i = row + 1; i > 0; i -= i&-i) {
            for (int j = col + 1; j > 0; j -= j&-j) {
                res += _bits[i][j];
            }
        }
        return res;
    } 
private:
    vector<vector<int>> _nums, _bits;
};