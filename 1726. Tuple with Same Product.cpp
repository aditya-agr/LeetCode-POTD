class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<long long, int> mp;
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                long long curr = nums[i]*nums[j];    
                cnt+=mp[curr]*8;
                mp[curr]++;
            }
        }
        return cnt;
    }
};