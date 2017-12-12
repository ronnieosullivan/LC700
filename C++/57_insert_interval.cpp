class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res = intervals;
        int i = 0, overlap = 0, n = intervals.size();
        while (i < n) {
            if (newInterval.end < intervals[i].start) break;
            else if (newInterval.start > intervals[i].end) {}
            else {
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
                overlap++;
            }
            i++;
        }
        if (overlap > 0) res.erase(res.begin() + i - overlap, res.begin() + i);
        res.insert(res.begin() + i - overlap, newInterval);
        return res;
    }
};