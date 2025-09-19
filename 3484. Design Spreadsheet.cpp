class Spreadsheet {
public:
    vector<vector<int>> ss;
    Spreadsheet(int rows) {
        ss.resize(rows+1, vector<int>(26));
    }
    
    void setCell(string cell, int value) {
        string num = cell.substr(1);
        int x = stoi(num);
        int y = cell[0]-'A';
        ss[x][y] = value;
    }
    
    void resetCell(string cell) {
        string num = cell.substr(1);
        int x = stoi(num);
        int y = cell[0]-'A';
        ss[x][y] = 0;
    }
    
    int getValue(string formula) {
        string f = formula.substr(1);
        int i = f.find('+');
        string a = f.substr(0, i);
        string b = f.substr(i+1);
        int res = 0;
        if(a[0]>='A' && a[0]<='Z'){
            string num = a.substr(1);
            int x = stoi(num);
            int y = a[0]-'A';
            res += ss[x][y];
        }
        else 
            res += stoi(a);

        if(b[0]>='A' && b[0]<='Z'){
            string num = b.substr(1);
            int x = stoi(num);
            int y = b[0]-'A';
            res += ss[x][y];
        }
        else 
            res += stoi(b);
        return res;
        
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */