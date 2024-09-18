class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> idx;
        for(int &it : nums)
            idx.push_back(to_string(it));
        sort(idx.begin(), idx.end(), [](string a, string b){
            return a+b > b+a;
        });
        string res="";
        for(string &s : idx)
            res += s;
        return res[0]=='0' ? "0" : res;
    }
};