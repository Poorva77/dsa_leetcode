class Solution {
    public int countPrimes(int n) {
        boolean[] prime= new boolean[n+1];
        Arrays.fill(prime,true);
        prime[0]=false;
        if(n>=1) prime[1]=false;
        for(int i=2;i*i<=n;i++){
            if(prime[i]){
                for(int j=i*i;j<=n;j+=i){
                    prime[j]=false;
                }
            }
        }
        int count=0;
        for(int i=1;i<n;i++){
            if(prime[i]) count++;
        }
        return count;
    }
}