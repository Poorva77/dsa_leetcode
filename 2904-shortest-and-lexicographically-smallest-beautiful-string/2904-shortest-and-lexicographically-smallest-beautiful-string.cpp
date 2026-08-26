class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size();
        int i=0;
        int ones=0;
        string ans="";
        int minLen=INT_MAX;
        for(int j=0;j<n;j++){
            // Count ones in the current window
            if(s[j]=='1')
                ones++;
            // Shrink the window if it has more than k ones
            while(ones>k){
                if(s[i]=='1')
                    ones--;
                i++;
            }
            // We found a beautiful substring
            if(ones==k){
                // Remove unnecessary leading zeros
                while(s[i]=='0')
                    i++;

                int len=j-i+1;
                string current=s.substr(i,len);
                // Update if the current substring is shorter
                if(len<minLen){
                    minLen=len;
                    ans=current;
                }
                // If lengths are equal, choose lexicographically smaller
                else if(len==minLen&&current<ans){
                    ans=current;
                }
            }
        }
        return ans;
    }
};