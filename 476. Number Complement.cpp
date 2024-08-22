class Solution {
public:
    int findComplement(int num) {
        int res=0, mul=1;
        while(num != 1){
            int rem = num%2;
            res += (1 - rem)*mul;
            mul *= 2;
            num /= 2;
        }
        return res;
    }
};