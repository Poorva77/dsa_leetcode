class Solution {
public:
    string removeDuplicateLetters(string s) {
        if(s.empty()) return "";
        vector<int> cnt(26,0);
        for(char c:s) cnt[c-'a']++;

        int pos=0;
        for(int i=0;i<s.size();i++){
            if(s[i]<s[pos]) pos=i;
            if(--cnt[s[i]-'a']==0) break;
        }
        char ch=s[pos];
        string rem=s.substr(pos+1);
        rem.erase(remove(rem.begin(),rem.end(),ch),rem.end());
        return ch+removeDuplicateLetters(rem);
    }
};