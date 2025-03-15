class Solution {
public:
    bool isPossible(vector<int> &nums, int k, int mid){
        int n = nums.size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(nums[i]<=mid){
                cnt++;
                i++;
            }
        }
        return cnt >= k;
    }
    int minCapability(vector<int>& nums, int k) {
        int l = *min_element(nums.begin(), nums.end());
        int h = *max_element(nums.begin(), nums.end());
        int res = h;
        while(l<=h){
            int mid =l + (h-l)/2;
            if(isPossible(nums, k , mid)){
                res = mid;
                h = mid - 1;
            }
            else
                l = mid + 1;
        }
        return res;
    }
};