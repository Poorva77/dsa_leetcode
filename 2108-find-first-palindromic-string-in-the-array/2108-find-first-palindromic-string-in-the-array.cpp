class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        string s="";
        for(string x:words){
            int l=0, r=x.size()-1;
            while(l<r){
                if(x[l]==x[r]){
                    l++;
                    r--;
                }
                else break;
            }
            if(l>=r){   //we got the palindrome 
                return x; 
            }
        }
        return "";
    }
};