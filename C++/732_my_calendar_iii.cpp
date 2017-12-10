// Solution 1:
// O(N^2)
class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        int res = 0;
        ++freq[start];
        --freq[end];
        int cnt = 0;
        for (auto f : freq) {
            cnt += f.second;
            res = max(cnt, res);
        }
        return res;
    }
private:
    map<int, int> freq;
};