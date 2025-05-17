class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> cnt(3);
        for(int x : nums)
            cnt[x]++;

        int i=0;
        for(int j=0; j<3; j++){
            while(cnt[j]--)
                nums[i++] = j;
        }
    }
};