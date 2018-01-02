class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (!v1.empty()) q.push({v1.begin(), v1.end()});
        if (!v2.empty()) q.push({v2.begin(), v2.end()});
    }

    int next() {
        if (q.empty()) return -1;
        auto front = q.front(); q.pop();
        int res = *(front.first);
        front.first++;
        if (front.first != front.second) q.push({front.first, front.second});
        return res;
    }

    bool hasNext() {
        return !q.empty();
    }
private:
    using It = vector<int>::iterator;
    queue<pair<It, It>> q;
};