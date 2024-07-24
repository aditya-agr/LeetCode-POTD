class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> vec;
        int n=nums.size();
        for(int i=0; i<n; i++){
            int tmp = nums[i], num=0, lvl=1;
            if(tmp<10)
                num = mapping[tmp];
            else{
                while(tmp){
                    int idx = tmp%10;
                    num += mapping[idx]*lvl;
                    tmp /= 10;
                    lvl *= 10;
                }
            }
            vec.push_back({num, i});
        }
        sort(vec.begin(), vec.end());
        vector<int> res;
        for(auto i : vec)
            res.push_back(nums[i.second]);
        return res;
    }
};