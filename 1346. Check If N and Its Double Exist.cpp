class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(int num : arr){
            if(mp.count(num*2))
                return true;
            if(num%2==0 && mp.count(num/2))
                return true;
            mp[num]++;
        }
        return false;
    }
};