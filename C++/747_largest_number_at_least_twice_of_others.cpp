class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int a = -1, b = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (a == -1) a = i;
            else if (b == -1) {
                b = i;
                if (nums[a] < nums[b]) swap(a, b);
            }
            else {
                if (nums[i] >= nums[a]) {
                    b = a;
                    a = i;
                }
                else if (nums[i] >= nums[b]) {
                    b = i;
                }
            }
        }
        if (a == -1 || b == -1 || nums[a] < nums[b] * 2) return -1;
        else return a;
    }
};

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if (nums.empty()) return -1;
        if (nums.size() == 1) return 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        for (int i = 0; i < nums.size(); i++) {
            q.emplace(nums[i], i);
            if (q.size() >= 3) q.pop();
        }
        auto a = q.top(); q.pop();
        auto b = q.top(); q.pop();
        if (a.first * 2 > b.first) return -1;
        else return b.second;
    }
};