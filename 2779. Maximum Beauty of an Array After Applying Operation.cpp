class Solution {
public:
    int binarySearch(vector<int> &nums, int target){
        int n = nums.size();
        int l=0, h=n-1, ans=INT_MIN;
        while(l<=h){
            int mid = l+(h-l)/2;
            if(nums[mid] <= target){
                l = mid+1;
                ans = mid;
            }
            else
                h = mid-1;
        }
        return ans;
    }
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        int res = INT_MIN;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            int x = nums[i];
            int y = x + 2*k;
            int j = binarySearch(nums, y);
            res = max(res, j-i+1);
        }
        return res;
    }
};