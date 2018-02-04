int wordBuddies(string word1, string word2) {
    if (word1.size() != word2.size()) return -1;
    vector<int> counter(128);
    int res = 0;
    unordered_multiset<string> s;
    for (int i = 0; i < word1.size(); i++) {
        if (word1[i] == word2[i]) continue;
        auto it = s.find(word2.substr(i, 1) + "_" + word1.substr(i, 1));
        if (it != s.end()) {
            s.erase(it);
            res++;
        }
        else {
            s.insert(word1.substr(i, 1) + "_" + word2.substr(i, 1));
        }
        counter[word1[i]]++;
        counter[word2[i]]--;
    }
    for (int i = 0; i < 128; i++) {
        if (counter[i] != 0) return -1;
    }
    return res + (s.empty() ? 0 : s.size() - 1);
}

int main() {
    std::cout << "Hello World!\n";
    cout << wordBuddies("", "") << endl;
    cout << wordBuddies("a", "") << endl;
    cout << wordBuddies("abc", "cba") << endl;
    cout << wordBuddies("abc", "cab") << endl;
    cout << wordBuddies("aaaabced", "bcdeaaaa") << endl;
    cout << wordBuddies("sss", "eee") << endl;
}