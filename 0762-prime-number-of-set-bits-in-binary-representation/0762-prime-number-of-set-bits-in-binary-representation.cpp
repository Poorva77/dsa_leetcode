class Solution {
public:
    bool isPrime(int n){
        if(n<2) return false;
        for(int i=2;i*i<=n;i++){
            if(n%i==0) return false;
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int ans=0;
        for(int i=left; i<=right; i++){
            int count=0;
            string num= bitset<32>(i).to_string();
            for(int j=0;j<num.size();j++){
                if(num[j]=='1') count++;
            }
            if(isPrime(count)){
                ans++;
            }
        }
        return ans;
    }
};