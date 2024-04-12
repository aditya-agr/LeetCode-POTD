class Solution {
public:
    int trap(vector<int>& height) {
        int n =height.size();
        int res=0;
        int l=0, r=n-1;
        int left=0, right=0;
        while(l<r){
            if(height[l]<=height[r]){
                if(height[l]>=left)
                    left = height[l];
                else
                    res += (left-height[l]);
                l++;
            }
            else{
                if(height[r]>=right)
                    right = height[r];
                else
                    res += (right-height[r]);
                r--;
            }
        }
        return res;
    }
};