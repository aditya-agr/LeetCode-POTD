class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i=0;
        while(i<n && nums[i]!=original)
            i++;
        for(i; i<n; i++){
            if(original == nums[i])
                original *= 2;
        }
        return original;
    }
};