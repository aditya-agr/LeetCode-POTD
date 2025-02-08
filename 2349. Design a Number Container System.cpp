class NumberContainers {
public:
    unordered_map<int, int> idxtonum;
    unordered_map<int, set<int>> numtoidx;
    NumberContainers() {}
    
    void change(int index, int number) {
        if(idxtonum.count(index)){
            int prev = idxtonum[index];
            numtoidx[prev].erase(index);
            if(numtoidx[prev].empty())
                numtoidx.erase(prev);
        }
        idxtonum[index] = number;
        numtoidx[number].insert(index);
    }
    
    int find(int number) {
        if(numtoidx[number].empty()) return -1; 
        int mn = *numtoidx[number].begin();
        return mn;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */