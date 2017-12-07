// Solution 1:
class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        Booking booking;
        booking.start = start;
        booking.end = end;
        if (s.count(booking)) return false;
        s.insert(booking);
        return true;
    }
private:
    struct Booking {
        int start;
        int end;
        bool operator< (const Booking& right) const
        {
            return end <= right.start;
        }
    };
    set<Booking> s;
};

// Solution 2:
class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it = cal.lower_bound(start);
        if (it != cal.end() && it->first < end) return false;
        if (it != cal.begin() && prev(it)->second > start) return false;
        cal[start] = end;
        return true;
    }
private:
    map<int, int> cal;
};