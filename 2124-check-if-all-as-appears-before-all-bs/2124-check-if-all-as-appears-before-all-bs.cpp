class Solution {
public:
    bool checkString(string s) {
        int n= s.size();
        string t=s;
        sort(t.begin(),t.end());
        return s==t;
    }
};