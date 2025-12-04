class Solution {
public:
    int countCollisions(string directions) {
        int cnt = 0;
        for(char c : directions){
            if(c == 'S')
                cnt--;
            cnt++;
        }
        int i=0, n=directions.size();
        while(i<n && directions[i]=='L')
            cnt--, i++;

        i = n-1;
        while(i>=0 && directions[i]=='R')
            cnt--, i--;
        return cnt;
    }
};