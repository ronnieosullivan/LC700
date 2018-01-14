class LRUCache {
public:
    LRUCache(int capacity)
    : _capacity(capacity) {
        
    }
    
    int get(int key) {
        auto it = _keys.find(key);
        if (it != _keys.end()) {
            _pairs.splice(_pairs.end(), _pairs, it->second); // move iterator to the back
            return it->second->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto it = _keys.find(key);
        if (it != _keys.end()) {
            _pairs.splice(_pairs.end(), _pairs, it->second); // move iterator to the back
            it->second->second = value;
        }
        else {
            if (_keys.size() >= _capacity) {
                _keys.erase(_pairs.front().first);
                _pairs.pop_front();
            }
            _pairs.push_back({key, value});
            _keys[key] = --(_pairs.end());
        }
    }
private:
    int _capacity;
    list<pair<int, int>> _pairs;
    unordered_map<int, list<pair<int, int>>::iterator> _keys;
};