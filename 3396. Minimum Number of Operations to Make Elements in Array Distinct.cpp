class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int x : nums){
            freq[x]++;
        }
        int cnt = 0;
        int n = nums.size();
        bool flag = true;
        for(auto it : freq)
            if(it.second>1)
                flag = false;
        if(flag == true)
            return cnt;
        for(int i=0; i<n; i+=3){
            flag = true;
            cnt++;
            for(int j=0; j<3 && i+j<n; j++)
                freq[nums[i+j]]--;
            for(auto it : freq){
                if(it.second>1)
                    flag = false;
            }
            if(flag == true)
                break;
        }
        return cnt;
    }

};