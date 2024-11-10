class Solution {
public:
    void update(int num, vector<int> &vec, int val){
        for(int i=0; i<32; i++){
            if((num>>i)&1)
                vec[i] += val;
        }
    }
    int getDecimal(vector<int> &vec){
        int sum = 0;
        for(int i=0; i<32; i++)
            if(vec[i])
                sum |= (1<<i);
        return sum; 
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        vector<int> vec(32, 0);
        int res = INT_MAX;

        while(j < n){
            update(nums[j], vec, 1);
            while(i<=j && getDecimal(vec)>=k){
                res = min(res, j-i+1);
                update(nums[i], vec, -1);
                i++;
            }
            j++;
        }
        return res == INT_MAX ? -1 : res;
    }
};