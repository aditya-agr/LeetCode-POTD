class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n = version1.length();
        int m = version2.length();
        int i=0, j=0;
        while(i<n || j<m){
            string v1 = "0";
            while(i<n && version1[i]!='.')
                v1 += version1[i++];
            i++;
            string v2 = "0";
            while(j<m && version2[j]!='.')
                v2 += version2[j++];
            j++;
            int ver1 = stoi(v1);
            int ver2 = stoi(v2);
            if(ver1 < ver2)
                return -1;
            if(ver1 > ver2)
                return 1;
        }
        return 0;
    }
};