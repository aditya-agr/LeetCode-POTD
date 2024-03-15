class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1, cnt=0;
        int n = nums.size();
        for(int i : nums){
            if(i==0){
                cnt++;
                continue;
            }
            prod*=i;
        }
        vector<int> res(n,0);
        cout<<cnt;
        if(cnt>1)
            return res;
        else if (cnt==1){
            for(int i=0; i<n; i++){   
                if(nums[i]==0)
                    res[i] = prod;    
            }
        }
        else{
            for(int i=0; i<n; i++)
                    res[i] = prod/nums[i];    
        }
        return res;
    }
};