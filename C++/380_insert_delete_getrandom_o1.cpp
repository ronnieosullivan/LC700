class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (m.count(val)) return false;
        else {
            v.push_back(val);
            m[val] = v.size() - 1;
            return true;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto it = m.find(val);
        if (!m.count(val)) return false;
        else {
            int index = m[val];
            m[v.back()] = index;
            swap(v[index], v[v.size() - 1]);
            v.pop_back();
            m.erase(val);
            return true;
        }
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return v[rand() % v.size()];
    }
private:
    unordered_map<int, int> m;
    vector<int> v;
};