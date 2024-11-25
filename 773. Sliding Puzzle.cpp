class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start = "";
        int n = board.size();
        int m = board[0].size();
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                start += to_string(board[i][j]);
        
        string target = "123450";
        unordered_map<int, vector<int>> mp;
        mp[0] = {1, 3};
        mp[1] = {0, 2, 4};
        mp[2] = {1, 5};
        mp[3] = {0, 4};
        mp[4] = {1, 3, 5};
        mp[5] = {2, 4};

        queue<string> que;
        que.push(start);
        int lvl = 0;
        unordered_set<string> visited;
        while(!que.empty()){
            int sz = que.size();
            for(int i=0; i<sz; i++){
                string curr  = que.front();
                que.pop();
                if(curr == target){
                    return lvl;
                }
                int idx = curr.find('0');
                for(int x : mp[idx]){
                    string nxt = curr;
                    swap(nxt[idx], nxt[x]);
                    if(visited.find(nxt) == visited.end()){
                        visited.insert(nxt);
                        que.push(nxt);
                    }
                }
            }
            lvl++;
        }
        return -1;
    }
};