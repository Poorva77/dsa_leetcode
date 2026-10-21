class Solution {
public:
    int minOperations(string s) {
        string t=s;
        sort(t.begin(),t.end());
        if(t==s) return 0; //means already sorted tha
        if(s.size()==2) return -1;
        if(s[0]==t[0] || s.back()==t.back()) return 1; //front/back is already sorted so only 1 sort at center is required
        for(int i=1;i<s.size()-1;i++){
            if(s[i]==t[0] || s[i]==t.back()) return 2; //for case- "jgg"
        }
        return 3; //for case- "edc"
    }
};