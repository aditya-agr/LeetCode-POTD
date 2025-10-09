class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        int m = mana.size();
        vector<long long> done(n);
        for(int i=0; i<m; i++){
            done[0] += mana[i]*skill[0]*1LL;
            for(int j=1; j<n; j++){
                done[j] = max(done[j], done[j-1]) + mana[i]*skill[j]*1LL;
            }
            for(int j=n-2; j>=0; j--){
                done[j] = done[j+1] - mana[i]*skill[j+1]*1LL;
            }
        }
        return done[n-1];
    }
};