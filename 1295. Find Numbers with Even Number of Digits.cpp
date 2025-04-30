class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res = 0;
        for(int x : nums){
            int cntOfDigits = 0;
            while(x){
                cntOfDigits++;
                x/=10;
            }
            if(cntOfDigits%2 == 0)
                res++;
        }
        return res;
    }
};ss