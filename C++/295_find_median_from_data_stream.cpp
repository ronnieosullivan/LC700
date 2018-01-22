class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        small.insert(num);
        large.insert(*small.rbegin());
        small.erase(--small.end());
        if (small.size() < large.size()) {
            small.insert(*large.begin());
            large.erase(large.begin());
        }
    }
    
    double findMedian() {
        return small.size() > large.size() ? *small.rbegin() : 0.5 * ((long)*small.rbegin() + (long)*large.begin());
    }
    
private:
    multiset<int> small, large;
};