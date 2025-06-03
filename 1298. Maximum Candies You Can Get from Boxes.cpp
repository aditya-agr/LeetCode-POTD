class Solution {
public:
    vector<int> st, can;
    vector<vector<int>> key, boxes;
    set<int> foundBox;
    int dfs(int box, vector<int> &vis){
        if(vis[box] == 1)
            return 0;
        if(st[box] == 0){
            foundBox.insert(box);
            return 0;
        }
        vis[box]  = 1;
        int candies = can[box];
        for(int v : boxes[box])
            candies += dfs(v, vis);
        for(int k : key[box]){
            st[k] = 1;
            if(foundBox.count(k)){
                candies += dfs(k, vis);
            }
        }
        return candies;
    }
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        st = status;
        can = candies;
        key = keys;
        boxes = containedBoxes;
        int candy = 0;
        int n = status.size();
        vector<int> visited(n);
        for(int box : initialBoxes){
            candy += dfs(box, visited);
        }
        return candy;
    }
};