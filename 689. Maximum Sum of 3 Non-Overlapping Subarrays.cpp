class Solution {
public:
    int t[20001][4];
    int helper(vector<int>& nums, int k, int i, int cnt){
        if(cnt == 0)
            return 0;
        if(i >= nums.size())
            return INT_MIN;
        if(t[i][cnt] != -1)
            return t[i][cnt];
        int take = nums[i] + helper(nums, k, i+k, cnt-1);
        int notake = helper(nums, k, i+1, cnt);
        return t[i][cnt] = max(take, notake);
    }
    void solve(vector<int> &nums, int k, int i, int cnt, vector<int> &res){
        if(cnt == 0)
            return;
        if(i>=nums.size())
            return;
        int starti = nums[i] + helper(nums, k, i+k, cnt-1);
        int startni = helper(nums, k, i+1, cnt);
        if(starti >= startni){
            res.push_back(i);
            solve(nums, k, i+k, cnt-1, res);
        }
        else
            solve(nums, k, i+1, cnt, res);
    }
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        memset(t, -1, sizeof(t));
        int n = nums.size();
        vector<int> pre;
        int curr=0;
        for(int i=0; i<k-1; i++)
            curr += nums[i];
        int i=0, j=k-1;
        while(j<n){
            curr += nums[j];
            pre.push_back(curr);
            curr -= nums[i]; 
            i++;
            j++;
        }
        vector<int> res;
        solve(pre, k, 0, 3, res);
        return res;
    }

};