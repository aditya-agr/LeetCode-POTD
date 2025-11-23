class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int mn11=10005, mn12=10005, mn21=10005, mn22=10005;
        int tot = 0;
        for(int x : nums){
            if(x%3 == 1){
                if(x < mn11){
                    mn12 = mn11;
                    mn11 = x;
                }
                else if(x < mn12)
                    mn12 = x;
            }
            if(x%3 == 2){
                if(x < mn21){
                    mn22 = mn21;
                    mn21 = x;
                }
                else if(x < mn22)
                    mn22 = x;
            }
            tot += x;
        }
        if(tot%3 == 1)
            tot -= min(mn11, mn21+mn22);
        if(tot%3 == 2)
            tot -= min(mn21, mn11+mn12);
        return tot;
    }
};ss