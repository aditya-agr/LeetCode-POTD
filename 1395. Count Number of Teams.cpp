class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int ans=0;
        for(int j=1; j<n-1; j++){
            int ls=0, lg=0, rs=0, rg=0;
            for(int i=0; i<j; i++){
                if(rating[i]>rating[j])
                    lg++;
                if(rating[i]<rating[j])
                    ls++;
            }
            for(int i=j+1; i<n; i++){
                if(rating[i]>rating[j])
                    rg++;
                if(rating[i]<rating[j])
                    rs++;
            }
            ans += (ls*rg);
            ans += (lg*rs);
        }
        return ans;
    }
};