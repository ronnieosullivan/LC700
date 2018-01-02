class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        _size = size;
        _sum = 0.0;
    }
    
    double next(int val) {
        _q.push(val);
        if (_q.size() > _size) {
            int toRemove = _q.front(); _q.pop();
            _sum = _sum - toRemove + val;
        }
        else {
            _sum += val;
        }
        return _sum / (int)(_q.size());
    }
private:
    int _size;
    queue<int> _q;
    double _sum;
};