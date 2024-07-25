class Solution {
public:
    // int partition(int l, int r, vector<int>&a){
    //     int pivot = a[l];
    //     int down=l+1, up=r;
    //     while(down<=up){
    //         while(down <= up && a[down] <= pivot)
    //             down++;
    //         while(down <= up && a[up] > pivot)
    //             up--;
    //         if(up > down)
    //             swap(a[up], a[down]);
    //     }
    //     a[l] = a[up];
    //     a[up] = pivot;
    //     return up;
    // }
    // void qsort(int l, int r, vector<int> &nums){
    //     if(l<r){
    //         int idx = partition(l, r, nums);
    //         qsort(l, idx-1, nums);
    //         qsort(idx+1, r, nums);
    //     }
    // }
    
    vector<int> sortArray(vector<int>& nums) {
        // int n = nums.size();
        // qsort(0, n-1, nums);
        // return nums;

        int minE = *min_element(begin(nums), end(nums));
        int maxE = *max_element(begin(nums), end(nums));
        unordered_map<int, int> mp;
        for(int &num : nums)
            mp[num]++;
        int i = 0;
        
        for(int num = minE; num <= maxE; num++) {
            while(mp[num] > 0) {
                nums[i] = num;
                i++;
                mp[num]--;
            }    
        }
        return nums;
    }
};