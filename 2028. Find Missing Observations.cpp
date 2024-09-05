class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int totsum = (n+m)*mean;
        for(int i : rolls)
            totsum -= i;
        
        if(totsum == n){
            vector<int> res(n, 1);
            return res;
        }
        else if(totsum < n)
            return {};
            
        if(totsum/n < 6 || (totsum/n == 6 && totsum%n==0)){
            vector<int> res(n);
            for(int i=0; i<n; i++){
                res[i] = min(6, totsum-(n-i-1));
                totsum -= res[i];
            }
            return res;
        }
        else 
            return {};

    }
};