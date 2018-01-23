class Logger {
public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        auto it = m.find(message);
        if (it == m.end()) {
            m[message] = timestamp;
            return true;
        }
        if (timestamp - it->second >= 10) {
            it->second = timestamp;
            return true;
        }
        return false;
    }
private:
    unordered_map<string, int> m;
};