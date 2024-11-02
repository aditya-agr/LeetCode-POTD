class Solution {
public:
    bool isCircularSentence(string sentence) {
        stringstream ss(sentence);
        string word;
        vector<string> arr;
        while(ss >> word)
            arr.push_back(word);
        int n = arr.size();
        if(arr[0][0] != arr[n-1].back())
            return false;
        for(int i=0; i<n-1; i++)
            if(arr[i].back() != arr[i+1][0])
                return false;
        return true;
    }

};