class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int> mp;
        int count=0;
        int maxcount=0;
        int left=0;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
            count++;
            while(mp[s[i]]>2){
                mp[s[left]]--;
                left++;
                count--;
            }
            maxcount=max(maxcount,count);
        }
        return maxcount;
    }
};