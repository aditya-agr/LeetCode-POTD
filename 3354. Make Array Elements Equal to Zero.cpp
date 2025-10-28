class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int count=0;
        if(n==1 && nums[0]==0)
            return 2;
        vector<int> left(n+1);
        left[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--)
            left[i] = nums[i] + left[i+1];
        int curr=0;
        for(int i=0; i<n; i++){
            curr += nums[i];
            if(nums[i] == 0){
                if((curr-left[i+1]) == 0)
                    count += 2;
                if(abs(curr-left[i+1]) == 1)
                    count += 1;
            }
        }
        return count;
    }
};