class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        vector<int> res;
        unordered_set<string> st = {"electronics", "grocery", "pharmacy", "restaurant"};
        for(int i=0; i<n; i++){
            bool flag = true;
            for(char c : code[i]){
                if(!isalnum(c) && c!='_'){
                    flag = false;
                    break;
                }
            }
            if(flag && isActive[i] && !code[i].empty() && st.contains(businessLine[i]))
                res.push_back(i);
        }
        auto comp = [&](int a, int b){
            if(businessLine[a] < businessLine[b])
                return true;
            else if(businessLine[a] > businessLine[b])
                return false;
            else
                return code[a] < code[b];
        };
        sort(res.begin(), res.end(), comp);
        vector<string> ans;
        for(int x : res)
            ans.push_back(code[x]);
        return ans;
    }
};