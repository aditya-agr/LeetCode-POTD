class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int sl=0, ft=0;
        do{
            sl=nums[sl];
            ft=nums[nums[ft]];
        }while(sl!=ft);
        sl=0;
        while(sl!=ft){
            sl=nums[sl];
            ft=nums[ft];
        }
        return sl;
    }
};