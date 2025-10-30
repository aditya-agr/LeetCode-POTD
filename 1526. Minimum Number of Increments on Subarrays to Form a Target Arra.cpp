class Solution {
public:
    // int solve(vector<int> &target, int st, int ed){
    //     if(st > ed)
    //         return 0;
    //     if(st == ed)
    //         return target[st];
        
    //     int mnEle = INT_MAX;
    //     for(int i=st; i<=ed; i++)
    //         mnEle = min(mnEle, target[i]);
    //     int mx = 0, st_=st;
    //     for(int i=st; i<=ed; i++){
    //         target[i] -= mnEle;
    //         if(target[i]==0){
    //             mx += solve(target, st_, i-1);
    //             st_ = i+1;
    //         }
    //     }
    //     mx += solve(target, st_, ed);
    //     return mx + mnEle;
    // }
    int minNumberOperations(vector<int>& target) {
        // int n = target.size();
        // return solve(target, 0, n-1);

        int n = target.size();
        int res = target[0];
        for(int i=1; i<n; i++){
            if(target[i] > target[i-1])
                res += target[i]-target[i-1];
        }
        return res;
    }
};