class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        istringstream iss(sentence);
        string word;
        int n = searchWord.size();
        int it=0;
        while(iss >> word){
            int m = word.size();
            int i=0, j=0;
            bool flag = true;
            cout<<word;
            while(i<n && j<m)
                if(searchWord[i++] != word[j++])
                    flag = false;
            if(flag && i==n)
                return it+1;
            it++;
        }
        return -1;
    }
};