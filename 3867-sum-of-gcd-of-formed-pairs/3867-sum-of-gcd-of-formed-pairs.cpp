class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> prefixGcd;
        int mx=0;

        for(int x:nums){
            mx=max(mx,x);
            prefixGcd.push_back(__gcd(x,mx));
        }

        sort(prefixGcd.begin(),prefixGcd.end());

        long long ans=0;
        int i=0,j=prefixGcd.size()-1;

        while(i<j){
            ans+=__gcd(prefixGcd[i],prefixGcd[j]);
            i++;
            j--;
        }

        return ans;
    }
};