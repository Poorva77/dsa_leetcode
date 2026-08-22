class Solution {
public:
    bool checkDivisibility(int n) {
        int original=n;
        int sum1=0;
        int sum2=1;
        while(n>0){
            int digit=n%10;
            sum1+=digit;
            sum2*=digit;
            n/=10;
        }
        int sum=sum1+sum2;
        return original%sum==0;
    }
};