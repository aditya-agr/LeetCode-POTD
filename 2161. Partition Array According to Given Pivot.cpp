class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> sm, lg;
        int same = 0;
        for(int x : nums){
            if(x<pivot)
                sm.push_back(x);
            else if(x>pivot)
                lg.push_back(x);
            else
                same++;
        }
        vector<int> res;
        for(int x : sm)
            res.push_back(x);
        while(same--)
            res.push_back(pivot);
        for(int x : lg)
            res.push_back(x);
        return res;
    }
};