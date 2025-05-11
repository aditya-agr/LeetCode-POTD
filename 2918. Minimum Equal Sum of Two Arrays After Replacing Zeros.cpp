class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1=0, sum2=0;
        bool zero1=false, zero2=false;
        for(int x : nums1){
            sum1 += (x==0) ? 1 : x;
            if(x == 0)
                zero1 = true;
        }
        for(int x : nums2){
            sum2 += (x==0) ? 1 : x;
            if(x == 0)
                zero2 = true;
        }
        if(sum1 == sum2)
            return sum1;
        else if(sum1 > sum2)
            return zero2 ? sum1 : -1;
        else
            return zero1 ? sum2 : -1;
    }
};