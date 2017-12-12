class Solution {
public:
    static bool compare(const Interval& a, const Interval& b) {
        return a.start == b.start? a.end > b.end : a.start < b.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if (intervals.empty()) return res;
        sort(intervals.begin(), intervals.end(), compare);
        int start = intervals[0].start, end = intervals[0].end;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start > end) {
                res.emplace_back(start, end);
                start = intervals[i].start;
                end = intervals[i].end;
            }
            else {
                end = max(intervals[i].end, end);
            }
        }
        res.emplace_back(start, end);
        return res;
    }
};