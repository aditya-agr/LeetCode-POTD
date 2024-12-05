class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        string s1 = "", s2 = "";
        for(int i=0; i<n; i++){
            if(start[i]=='L' || start[i]=='R')
                s1 += start[i];
            if(target[i]=='L' || target[i]=='R')
                s2 += target[i];
        }
        if(s1 != s2)
            return false;
        int i=0, j=0;
        while(i<n && j<n){
            while(i<n && start[i]=='_') i++;
            while(j<n && target[j]=='_') j++;
            if(start[i]=='L' && i<j)
                return false;
            if(start[i]=='R' && i>j)
                return false;
            i++; j++;
        }
        return true;
    }
};