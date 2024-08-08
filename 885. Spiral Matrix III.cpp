class Solution {
public:
    int direction[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int size=0, dir=0;
        int x=rStart, y=cStart;
        vector<vector<int>> res;
        res.push_back({x, y});
        while(res.size() < rows*cols){
            if(dir%2==0)
                size++;
            for(int i=0; i<size; i++){
                x += direction[dir][0];
                y += direction[dir][1];
                if(x>=0 && x<rows && y>=0 && y<cols)
                    res.push_back({x, y});
            }
            dir = (dir+1)%4;
        }
        return res;
    }
};