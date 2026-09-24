class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            int c = nums[i];
            int sum = 0;
            while(c){
                sum += c%10;
                c /= 10;
            }
            if(sum == i)
                return i;
        }
        return -1;
    }
};