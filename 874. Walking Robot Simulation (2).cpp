class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0;
        int y = 0;
        int cur = 0;
        int res = 0;
        set<vector<int>> st(obstacles.begin(), obstacles.end());
        for(int &c : commands){
            if(c == -1)
                cur = (cur+1)%4;
            else if(c == -2)
                cur = (cur-1+4)%4;
            else{
                if(cur == 0){
                    for(int i=0; i<c; i++){
                        if(st.count({x, y+1}))
                            break;
                        y++;
                    }
                }
                else if(cur == 1){
                    for(int i=0; i<c; i++){
                        if(st.count({x+1, y}))
                            break;
                        x++;
                    }
                }
                else if(cur == 2){
                    for(int i=0; i<c; i++){
                        if(st.count({x, y-1}))
                            break;
                        y--;
                    }
                }
                else if(cur == 3){
                    for(int i=0; i<c; i++){
                        if(st.count({x-1, y}))
                            break;
                        x--;
                    }
                }
            }
            res = max(res, x*x + y*y);
        }
        return res;
    }
};