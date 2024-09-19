class Solution {
public:
    unordered_map<string, vector<int>> mp;
    vector<int> diffWaysToCompute(string expr) {
        if(mp.find(expr) != mp.end())
            return mp[expr];
        int n = expr.size();
        vector<int> res;
        for(int i=0; i<n; i++){
            if(expr[i]=='+' || expr[i]=='-' || expr[i]=='*'){
                vector<int> left = diffWaysToCompute(expr.substr(0, i));
                vector<int> right = diffWaysToCompute(expr.substr(i+1));
                for(int &x : left){
                    for(int &y : right){
                        if(expr[i]=='+')
                            res.push_back(x+y);
                        if(expr[i]=='-')
                            res.push_back(x-y);
                        if(expr[i]=='*')
                            res.push_back(x*y);
                    }
                }
            }
        }
        if(!res.size())
            res.push_back(stoi(expr));
        mp[expr] = res;
        return res;
    }
};