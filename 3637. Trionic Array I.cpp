class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        int p=-1, q=-1;
        int i=0;
        
        while(i<n-1 && nums[i]<nums[i+1])
            i++;
        if(i==0 || i==n-1)
            return false;
        p = i;

        while(i<n-1 && nums[i]>nums[i+1])
            i++;
        if(i==p || i==n-1)
            return false;
        q = i;

        while(i<n-1 && nums[i]<nums[i+1])
            i++;
        if(i==p || i==n-1)
            return true;

        return false;
        
    }
};