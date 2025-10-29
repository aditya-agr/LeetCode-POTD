class Solution {
public:
    int smallestNumber(int n) {
        int it = 1, p = 2;
        while(it < n){
            it += p;
            p *= 2;
        }
        return it;
    }
};