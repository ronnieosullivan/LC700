class Solution {
public:
    bool isValidSerialization(string preorder) {
        istringstream in(preorder);
        string t = "";
        int degree = 1;
        while (getline(in, t, ',')) {
            if (degree <= 0) return false;
            if (t == "#") degree--;
            else degree++;
        }
        return degree == 0;
    }
};