class Solution {
public:
    long long countCommas(long long n) {
        if(n<1000)return 0;
        long long ans=0;
        long long power=1000;
        while(power<=n){
            ans+=n-power+1;
            if(power>n/1000)break;
            power*=1000;
        }
        return ans;
    }
};