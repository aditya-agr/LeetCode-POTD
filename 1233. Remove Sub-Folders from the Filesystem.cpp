class TrieNode{
    public:
    bool isEnd;
    TrieNode* children[27];

    TrieNode(){
        isEnd = false;
        for(int i=0; i<27; i++)
            children[i] = NULL;
    } 
};
class Solution {
public:
    TrieNode* root;
    void insert(string &s){
        TrieNode* crawler = root;
        for(char ch : s){
            int idx = (ch=='/') ? 26 : ch-'a';
            if(crawler->children[idx] == NULL)
                crawler->children[idx] = new TrieNode();
            crawler = crawler->children[idx];
        }
        crawler->isEnd = true;
    }
    string search(string &s){
        TrieNode* crawler = root;
        int n=s.length();
        for(int i=0; i<n; i++){
            int idx = (s[i]=='/') ? 26 : s[i]-'a';
            crawler = crawler->children[idx];
            if(crawler->isEnd && s[i+1]=='/')
                return "";
        }
        return s;
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        root = new TrieNode();
        for(string s : folder)
            insert(s);
        vector<string> vec;
        for(string s : folder){
            string res = search(s);
            if(res != "")
                vec.push_back(res);
        }
        return vec;
    }
};