
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long score = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            nums[i] = abs(nums[i]);
        }
        sort(nums.begin(), nums.end());
        int i=0, j=n-1;
        while(i<=j){
            score += nums[j]*nums[j];
            j--;
            if(i<=j){
                score -= nums[i]*nums[i];
                i++;
            }
        }
        return score;
    }
};