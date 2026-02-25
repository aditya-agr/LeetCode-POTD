class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        auto comp = [](int a, int b){
            int cnta = __builtin_popcount(a);
            int cntb = __builtin_popcount(b);
            if(cnta == cntb)
                return a < b;
            return cnta < cntb;
        };
        sort(arr.begin(), arr.end(), comp);
        return arr;
    }
};