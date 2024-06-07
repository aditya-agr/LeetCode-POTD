class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> st(dictionary.begin(), dictionary.end());
        stringstream ss(sentence);
        string word, res="";
        while(getline(ss, word, ' ')){
            string t="";
            int flag=0;
            for(char &c : word){
                t+=c;
                if(st.count(t)){
                    res += t + " ";
                    flag=1;
                    break;
                }
            }
            if(flag==0)
                res += word + " ";
        }
        res.pop_back();
        return res;
    }
};