class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        for (auto a : nums) {
            q.push(a);
            if (q.size() > k) {
                q.pop();
            }
        }
        return q.top();
    }
};