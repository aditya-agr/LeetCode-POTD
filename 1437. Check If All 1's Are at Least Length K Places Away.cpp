class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int cnt = 0;
        for(int x : nums){
            if(x == 1){
                if(cnt <= 0)
                    cnt = k;
                else
                    return false;
            }
            else
                cnt -= 1;
        }
        return true;
    }
};