class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int res = 0;
        unordered_set<int> st = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
        for(int i=left; i<=right; i++){
            int bits = __builtin_popcount(i);
            if(st.count(bits))
                res++;
        }
        return res;
    }
};