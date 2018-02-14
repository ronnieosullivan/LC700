class Solution {
public:
    int kthGrammar(int N, int K) {
        if (N <= 1) return 0;
        int t = kthGrammar(N - 1, (K - 1) / 2 + 1);
        if (t == 1) return (K - 1) % 2 == 1 ? 0 : 1;
        else return (K - 1) % 2 == 1 ? 1 : 0;
    }
};