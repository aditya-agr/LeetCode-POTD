class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum = 0, curr = 0;
        unordered_set<int> st;
        int i=0, j=0;
        int n = nums.size();
        while(j<n){
            while(st.count(nums[j]) > 0){
                curr -= nums[i];
                st.erase(nums[i]);
                i++;
            }
            curr += nums[j];
            st.insert(nums[j]);
            if(j-i+1 == k){
                sum = max(sum, curr);
                curr -= nums[i];
                st.erase(nums[i]);
                i++;
            }
            j++;
        }
        return sum;
    }
};