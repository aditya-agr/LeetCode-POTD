class Solution {
public:
    int count(vector<int> &nums, int d){
        int i=0;
        int j=1;
        int n = nums.size(), cnt=0;
        while(j<n){
            while(nums[j]-nums[i] > d)
                i++;
            cnt += j-i;
            j++;
        }
        return cnt;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n=nums.size(), res=0;
        sort(nums.begin(), nums.end());
        int l=0; 
        int h=nums[n-1]-nums[0];
        while(l<=h){
            int mid = l + (h-l)/2;
            int cnt = count(nums, mid);
            if(cnt<k)
                l = mid+1;
            else{
                res = mid;
                h = mid-1;
            }
        }
        return res;
    }
};