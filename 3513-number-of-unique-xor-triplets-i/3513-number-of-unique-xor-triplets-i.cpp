class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n==1) return 1; 
        if (n==2) return 2; 
        
        //__builtin_clz(n) counts leading zeros of n in a 32-bit int.
        int bitLength = 32 - __builtin_clz(n);
        
        //1<<bitLength computes 2^(bitLength), which is the total count of unique numbers reachable in the full range [0, 2^(bitLength) - 1].
        return 1 << bitLength;
    }
};