class Solution {
public:
    vector<int> ans;
    void solve(int i, int n){
        if(i>n)
            return;
        ans.push_back(i);
        for(int x=0; x<=9; x++){
            string tmp = to_string(i)+to_string(x);
            solve(stoi(tmp), n);
        }
    }
    vector<int> lexicalOrder(int n) {
        for(int i=1; i<=9; i++)
            solve(i, n);
        return ans;
    }
};