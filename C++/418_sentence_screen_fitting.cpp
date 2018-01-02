class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string t = "";
        for (auto& s : sentence) {
            if (s.size() > cols) return 0;
            t += s + " ";
        }
        int len = t.size(), start = 0;
        for (int i = 0; i < rows; i++) {
            start += cols;
            while (start > 0 && t[start % len] != ' ') start--;
            start++;
        }
        return start / len;
    }
};