class Solution {
public:
    bool isnonDec(vector<int> &nums){
        int n = nums.size();
        for(int i=1; i<n; i++){
            if(nums[i] < nums[i-1])
                return false;
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int cnt = 0;
        while(!isnonDec(nums)){
            int idx = -1, mn = INT_MAX;
            int n = nums.size();
            for(int i=0; i<n-1; i++){
                if(nums[i] + nums[i+1] < mn){
                    mn = nums[i]+nums[i+1];
                    idx = i;
                }
            }
            nums.erase(nums.begin()+idx);
            nums.erase(nums.begin()+idx);
            nums.insert(nums.begin()+idx, mn);
            cnt++;
        }
        return cnt;
    }
};