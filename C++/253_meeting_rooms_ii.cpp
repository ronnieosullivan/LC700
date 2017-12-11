class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });
        int res = 0;
        priority_queue<int, vector<int>, greater<int>> q;
        for (auto a : intervals) {
            while (!q.empty() && q.top() <= a.start) {
                q.pop();
            }
            q.push(a.end);
            res = max(res, (int)(q.size()));
        }
        return res;
    }
};