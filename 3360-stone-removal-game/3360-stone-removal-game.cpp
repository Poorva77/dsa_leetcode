class Solution {
public:
    bool canAliceWin(int n) {
        if(n<10) return false;
        int stones=10;
        int count=0;
        while(n>=stones){
            n-=stones;
            stones--;
            count++;
        }
        return count%2!=0;
    }
};