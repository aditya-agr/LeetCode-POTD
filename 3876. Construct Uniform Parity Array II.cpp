class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int even = 0, odd = 0, mn = INT_MAX;
        for(int i=0; i<n; i++){
            if(nums1[i]%2)
                odd++;
            else
                even++;
            mn = min(mn, nums1[i]);
        }
        if(odd == n || even == n)
            return true;
        
        if(mn%2)
            return true;
        return false;
    }

};