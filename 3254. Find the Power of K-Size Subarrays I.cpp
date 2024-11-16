class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res(n-k+1, -1);
        // for(int i=k-1; i<n; i++){
        //     bool flag = true;
        //     for(int j=i-k+2; j<=i; j++){
        //         if(nums[j]-1 != nums[j-1])
        //             flag = false;
        //     }
        //     if(flag)
        //         res.push_back(nums[i]);
        //     else
        //         res.push_back(-1);
        // } 

        int count=1, x=0;
        for(int i=1; i<k; i++){
            if(nums[i] == nums[i-1]+1)
                count++;
            else 
                count = 1;
        }
        if(count == k)
            res[0] = nums[k-1];

        for(int i=k; i<n; i++){
            if(nums[i] == nums[i-1]+1)
                count++;
            else 
                count = 1;

            if(count >= k)
                res[i-k+1] = nums[i];
        }
        return res;
    }
};