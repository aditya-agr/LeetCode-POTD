class Solution {
public:
    bool isValid(string word) {
        if(word.size() < 3)
            return false;
        bool conso=false, vow=false;
        string v = "aeiou";
        for(char c : word){
            if((c>='a' && c<='z') || (c>='A' && c<='Z')){
                c = tolower(c);
                if(v.find(c) == string::npos)
                    conso = true;
                else
                    vow = true;
            }
            else if(!(c>='0' && c<='9'))
                return false;
        }
        return conso && vow;
    }
};