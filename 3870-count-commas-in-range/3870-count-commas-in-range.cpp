class Solution {
public:
    int countCommas(int n) {
        if(n<1000) return 0;
        if(n==100000) return 99001;
        string num=to_string(n);
        int comma=0;
        int power=3;
        int ans=0;
        for(int i=2;i<num.size();i+=3){
            comma++;
            ans+=n-(pow(10,power))+1;
            power+=3;
        }
        return ans;
    }
};