class Solution {
public:
    int sumDigits(int x){
        int sum = 0;
        while(x > 0){
            sum += x%10;
            x /= 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        for(int x : nums){
            int sum = sumDigits(x);
            mp[sum].push_back(x);
        } 
        int mx = -1;
        for(auto it : mp){
            vector<int> vec = it.second;
            if(vec.size() > 1){
                sort(vec.rbegin(), vec.rend());
                mx = max(mx, vec[0]+vec[1]);
            }
        }
        return mx;
    }
};