class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26,0);
        for(char c:s)
            freq[c-'a']++;
        string left = "";
        char mid = '\0';
        for (int i=0;i<26;i++){
            left+=string(freq[i]/2,char('a'+i));
            if(freq[i]%2)
                mid=char('a'+i);
        }
        string right = left;
        reverse(right.begin(), right.end());
        if (mid == '\0')
            return left + right;
        return left + mid + right;
    }
};
/*1)Count the frequency of each character.
2)Build the left half in alphabetical order.
3)If any character has an odd frequency, put one occurrence in the middle.
4)Reverse the left half to form the right half.*/