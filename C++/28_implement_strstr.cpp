// Solution 1:
// template, preferred
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size(), i = 0, j = 0;
        vector<int> next(n, 0);
        getNext(needle, next);
        while (i < m && j < n) {
            while (j > 0 && haystack[i] != needle[j]) j = next[j - 1];
            cout << j << endl;
            j += (haystack[i] == needle[j] ? 1 : 0);
            i++;
        }
        return (j == n) ? i - j : -1;
    }
    void getNext(const string& needle, vector<int>& next) {
        int n = needle.size();
        for (int i = 1; i < n; ++i) {
            int j = next[i - 1];
            while (j > 0 && needle[i] != needle[j]) j = next[j - 1];
            next[i] = j + (needle[i] == needle[j]);
        }
    }
};

// Solution 2:
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size(), i = 0, j = 0;
        vector<int> next(n, -1);
        getNext(needle, next);
        while (i < m && j < n) {
            if (j == - 1 || haystack[i] == needle[j]) {
                ++i; ++j;
            } else {
                j = next[j];
            }
        }
        return (j == n) ? i - j : -1;
    }
    void getNext(const string& p, vector<int>& next) {
        int n = p.size(), k = -1, j = 0;
        while (j < n - 1) {
            if (k == -1 || p[j] == p[k]) {
                ++k; ++j;
                next[j] = (p[j] != p[k]) ? k : next[k];
            } else {
                k = next[k];
            }
        }
    }
};