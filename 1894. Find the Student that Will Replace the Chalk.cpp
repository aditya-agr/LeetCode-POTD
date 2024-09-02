class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long tot=0;
        for(int i : chalk)
            tot += i;
        k = k%tot;
        for(int i=0; i<chalk.size(); i++){
            if(chalk[i]<=k)
                k -= chalk[i];
            else 
                return i;
        }
        return 0;
    }
};