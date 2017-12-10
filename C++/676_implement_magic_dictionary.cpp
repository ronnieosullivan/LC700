// Solution 1:
class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (string word : dict) s.insert(word);
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        for (int i = 0; i < word.size(); ++i) {
            char t = word[i];
            for (char c = 'a'; c <= 'z'; ++c) {
                if (c == t) continue;
                word[i] = c;
                if (s.count(word)) return true;
            }
            word[i] = t;
        }
        return false;
    }
private:
    unordered_set<string> s;
};


// Solution 2:
class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        _dict.clear();
        for (auto word : dict) {
            string origin = word;
            for (int i = 0; i < word.size(); ++i) {
                char tmp = word[i];
                word[i] = '#';
                if (_dict.count(word)) _dict[word] = "";
                else _dict[word] = origin;
                word[i] = tmp;
            }
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        string origin = word;
        for (int i = 0; i < word.size(); ++i) {
            char tmp = word[i];
            word[i] = '#';
            if (_dict.count(word) && (_dict[word] == "" || _dict[word] != origin)) return true;
            word[i] = tmp;
        }
        return false;
    }
private:
    unordered_map<string, string> _dict;
};