class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        unordered_map<int, int> mp;
        for(int num : nums)
            mp[num]++;
        int mx = 0;
        for(auto it : mp)
            if(it.second > mx)
                mx = it.second;
        if(numOperations == 0)
            return mx;
        int mxele=0;
        for(int num : nums)
            mxele = max(num, mxele);
        int sze = mxele+1;
        vector<int> frequency(sze);
        for(int num : nums)
            frequency[num]++;
        for(int i=1; i<sze; i++)
            frequency[i] += frequency[i-1];
        int ans=0;
        for(int i=0; i<sze; i++){
            int low = frequency[max(i-k-1, 0)];
            int high = frequency[min(i+k, sze-1)];
            int total = high - low;
            int op = min(numOperations, total-mp[i]);
            ans = max(ans, mp[i]+op);
        }
        return ans;
    }
};