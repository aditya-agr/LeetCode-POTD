class Solution {
public:
    char kthCharacter(int k) {
        int n = __builtin_popcount(k-1);
        return 'a'+n;
    }
};