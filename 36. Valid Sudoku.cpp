class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> row[9];
        unordered_set<char> col[9];
        unordered_set<char> box[9];

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] == '.')
                    continue;
                int idx = (i/3)*3 + (j/3);
                char val = board[i][j];
                if(row[i].count(val) || col[j].count(val) || box[idx].count(val))
                    return false;
                row[i].insert(val);
                col[j].insert(val);
                box[idx].insert(val);
            }
        }
        return true;
    }
};