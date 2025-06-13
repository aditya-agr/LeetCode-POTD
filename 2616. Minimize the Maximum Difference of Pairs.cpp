class Solution {
public:
    bool isValid(int mid, vector<int>& nums, int p){
        int i = 0; 
        int n = nums.size();
        int count = 0;
        while(i<n-1){
            if(nums[i+1]-nums[i] <= mid){
                count++;
                i += 2;
            }
            else
                i++;
        }
        return count >= p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0;
        int h = nums[n-1] - nums[0];
        int res = -1;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(isValid(mid, nums, p)){
                res = mid;
                h = mid-1;
            }
            else
                l = mid+1;
        }
        return res;
    }
};