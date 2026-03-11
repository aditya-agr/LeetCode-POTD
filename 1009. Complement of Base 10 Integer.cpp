
class Solution {
public:
    int bitwiseComplement(int n) {
        int res = 0, it = 1;
        if(n == 0)
            return 1;
        while(n){
            int rem = n%2;
            res = res + (1-rem)*it;
            it *= 2;
            n /= 2;
        }
        return res;
    }
};