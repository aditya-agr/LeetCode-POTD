class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int major = -1, cnt = 0;
        for(int &x : nums){
            if(cnt <= 0){
                major = x;
                cnt = 1;
            }
            else if(major == x)
                cnt++;
            else
                cnt--;
        }
        int cntMaj = 0;
        for(int &x : nums)
            if(x == major) 
                cntMaj++;
        
        int n = nums.size();
        cnt = 0;
        for(int i=0; i<n; i++){
            int n1 = i+1;
            int n2 = n-i-1;
            if(nums[i] == major){
                cnt++;
                cntMaj--;
            }
            if(cnt*2 > n1 && cntMaj*2 > n2)
                return i;
        }
        return -1;
    }
};