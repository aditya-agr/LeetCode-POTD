class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = part.size();
        int i=0;
        while(true){
            if(s.find(part) == string::npos)
                break;
            int idx = s.find(part);
            s.erase(idx, n);
        }
        return s;
    }

};