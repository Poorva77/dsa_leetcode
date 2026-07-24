class Solution {
public:
    int maxVowels(string s, int k) {
        int count = 0;
        //vowels in first window
        for(int i=0;i<k;i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
                count++;
        }
        int ans = count;
        //Slide the window
        for(int i=k;i<s.size();i++){
            //Remove left character
            if(s[i-k]=='a'||s[i-k]=='e'||s[i-k]=='i' || s[i-k]=='o' || s[i-k]=='u')
                count--;
            // Add right character
            if (s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
                count++;
            ans=max(ans,count);
        }
        return ans;
    }
};