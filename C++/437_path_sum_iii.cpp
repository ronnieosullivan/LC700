class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> m;
        m[0] = 1;
        return helper(root, sum, 0, m);
    }
    int helper(TreeNode* node, int sum, int curSum, unordered_map<int, int>& m) {
        if (!node) return 0;
        curSum += node->val;
        int res = 0;
        auto it = m.find(curSum - sum);
        if (it != m.end()) res = it->second;
        ++m[curSum];
        res += helper(node->left, sum, curSum, m) + helper(node->right, sum, curSum, m);
        --m[curSum];
        return res;
    }
};