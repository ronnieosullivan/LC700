class LFUCache {
public:
    LFUCache(int capacity)
    : _capacity(capacity)
    , _minFreq(0) {}
    
    int get(int key) {
        if (keys.count(key) == 0) return -1;
        m[freq[key] + 1].splice(m[freq[key] + 1].end(), m[freq[key]], keys[key]);
        cout << freq[key] << endl;
        if (m[freq[key]].empty() && _minFreq == freq[key]) {
            m.erase(freq[key]);
            _minFreq++;
        }
        freq[key]++;
        return keys[key]->second;
    }
    
    void put(int key, int value) {
        if (_capacity == 0) return;
        int t = get(key);
        if (t != -1) {
            keys[key]->second = value;
        }
        else {
            if (keys.size() >= _capacity) {
                // remove least frequent item
                int keyToRemove = m[_minFreq].front().first;
                freq.erase(keyToRemove);
                keys.erase(keyToRemove);
                m[_minFreq].pop_front();
            }
            m[1].push_back({key, value});
            freq[key] = 1;
            keys[key] = --(m[1].end());
            _minFreq = 1;
        }
    }
private:
    int _capacity;
    int _minFreq;
    using List = list<pair<int, int>>;
    unordered_map<int, List> m; // freq -> list of KV pairs
    unordered_map<int, int> freq; // key -> freq
    unordered_map<int, List::iterator> keys; // key -> KV pair iterator
};