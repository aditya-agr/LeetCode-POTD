class Solution {
public:
    bool isVowel(char c){
        c = tolower(c);
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    string toLower(string &s){
        string res = "";
        for(char c : s)
            res += tolower(c);
        return res;
    }
    string toVowel(string &s){
        string res = "";
        for(char c : s)
            if(isVowel(c))
                res += '@';
            else
                res += c;
        return res;
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> words(wordlist.begin(), wordlist.end());
        unordered_map<string, string> lower;
        unordered_map<string, string> vowel;
        for(string &s : wordlist){
            string l = toLower(s);
            string v = toVowel(l);
            if(!lower.count(l))
                lower[l] = s;
            if(!vowel.count(v))
                vowel[v] = s; 
        }
        vector<string> res;
        for(string &s : queries){
            if(words.count(s))
                res.push_back(s);
            else{
                string l = toLower(s);
                string v = toVowel(l);
                if(lower.count(l))
                    res.push_back(lower[l]);
                else if(vowel.count(v))
                    res.push_back(vowel[v]);
                else
                    res.push_back("");
            }
        }
        return res;
    }
};