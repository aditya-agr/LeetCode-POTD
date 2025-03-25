class Solution {
public:
    bool checkValidCuts(int m, vector<vector<int>>& rectangles) {
        int n = rectangles.size();
        vector<vector<int>> x, y;
        for(vector<int> r : rectangles){
            x.push_back({r[0], r[2]});
            y.push_back({r[1], r[3]});
        }
        
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        
        vector<vector<int>> vecx;
        vecx.push_back(x[0]);
        for(int i=1; i<n; i++){
            if(vecx.back()[1]>x[i][0])
                vecx.back()[1] = max(vecx.back()[1],x[i][1]);
            else
                vecx.push_back(x[i]);
        }
        cout<<vecx.size();
        if(vecx.size()>2)
            return true;
        
        vector<vector<int>> vecy;
        vecy.push_back(y[0]);
        for(int i=1; i<n; i++){
            if(vecy.back()[1]>y[i][0])
                vecy.back()[1] = max(vecy.back()[1],y[i][1]);
            else
                vecy.push_back(y[i]);
        }
        cout<<vecy.size();
        if(vecy.size()>2)
            return true;
        
        return false;
    }
};