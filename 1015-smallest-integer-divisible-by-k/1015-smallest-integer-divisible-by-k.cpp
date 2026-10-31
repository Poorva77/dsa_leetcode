class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%2==0 || k%5==0) return -1;
        int n=1;
        int count=1;
        while(n%k!=0){
            n=(n*10+1)%k;  //store only remainder so %k is imp
            count++;
        }
        return count;
    }
};