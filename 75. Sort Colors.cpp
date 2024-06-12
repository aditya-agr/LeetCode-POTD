class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l=0, m=0, h=nums.size()-1;
        while(m<=h){
            if(nums[m]==1)
                m++;
            else if(nums[m]==2)
                swap(nums[h--], nums[m]);
            else{
                if(m!=l)
                    swap(nums[m], nums[l]);
                m++;
                l++;
            }
        }
    }
};
