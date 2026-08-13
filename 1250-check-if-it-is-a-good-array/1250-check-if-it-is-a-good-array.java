class Solution {
    //EUCLID'S ALGO - PLA
    public static int gcd(int a, int b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
    public boolean isGoodArray(int[] nums) {
        int g=nums[0];
        for(int i=1;i<nums.length;i++){
            g=gcd(g,nums[i]);
        }
        return g==1;
    }
}