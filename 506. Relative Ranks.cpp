class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> vec = score;
        sort(vec.begin(), vec.end(), greater<int>());
        int n = score.size();
        vector<string> res(n);
        for(int i=0; i<n; i++){
            int j=0;
            for(j=0; j<n; j++){
                if(vec[j]==score[i])
                    break;
            }
            if(j==0) res[i]="Gold Medal";
            else if(j==1) res[i]="Silver Medal";
            else if(j==2) res[i]="Bronze Medal";
            else res[i] = to_string(j+1);
        }
        return res;
    }
};