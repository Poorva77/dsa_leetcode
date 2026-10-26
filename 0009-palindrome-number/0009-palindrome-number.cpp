class Solution {
public:
    bool isPalindrome(int x) {
        long long rev=0; 
        int temp=x;
        if(x<0){
            return false;
        }
        
        while(temp>0){
            rev=rev*10 + temp%10;
            temp/=10;
        }
        return x==rev;
    }
};