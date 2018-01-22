// Solution 1:
class Solution {
public:
    string crackSafe(int n, int k) {
        string s = string(n - 1, '0');
        unordered_set<string> st;
        //(k) (k) (k) (k) : k*k*k*k = k^4 => k^n, all cases
        int total = (int)pow(k,n);
        int count = 0;
        while (count != total) {
            string base_str = s.substr((int)s.size() - n + 1);
            for(int digt = k - 1; digt >= 0; --digt){
                string temp = base_str + to_string(digt);
                if (!st.count(temp)) {
                    st.insert(temp);
                    s += to_string(digt);
                    count++;
                    break;
                }
            }
        }
        return s;
    }
};