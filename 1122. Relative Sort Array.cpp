class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> mp;
        for(int &i : arr1)
            mp[i]++;
        int j=0;
        for(int &i : arr2){
            while(mp[i]){
                mp[i]--;
                arr1[j++] = i;
            }
        }
        for(auto &i : mp){
            while(i.second){
                i.second--;
                arr1[j++] = i.first;
            }
        }
        return arr1;
    }
};