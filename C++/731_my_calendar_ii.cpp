//


// Solution 2:
// Not accepted
// Reason: when operator== is not transferrable, i.e. a == b, b == c, but a != c, 
// set does not behave the right way.
class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        Booking booking;
        booking.start = start;
        booking.end = end;
        if (s.count(booking) > 2) return false;
        if (s.count(booking) == 2) {
            auto ret = s.equal_range(booking);
            set<Booking> tmp;
            for (auto it = ret.first; it != ret.second; it++) {
                if (tmp.count(*it)) return false;
                else tmp.insert(*it);
            }
        }
        s.insert(booking);
        return true;
    }
private:
    struct Booking {
        int start;
        int end;
        bool operator< (const Booking& right) const {
            return end <= right.start;
        }
        bool operator== (const Booking& right) const {
            return !(end <= right.start || start >= right.end);
        }
        friend std::ostream& operator<<(std::ostream& o, const Booking& booking){
            return o << booking.start << ", " << booking.end;
        }
    };
    
    multiset<Booking> s;
};
