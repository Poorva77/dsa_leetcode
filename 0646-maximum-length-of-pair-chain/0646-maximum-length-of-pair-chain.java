class Solution {
    public int findLongestChain(int[][] pairs) {
        //activity selection - PLA
        Arrays.sort(pairs,(a,b)->a[1]-b[1]);  //IMP -ending time comparision
        int selected =0;
        int count=1;
        for(int i=1;i<pairs.length;i++){
            if(pairs[i][0]>pairs[selected][1]){
                selected =i;
                count++;
            }
        }
        return count;
    }
}