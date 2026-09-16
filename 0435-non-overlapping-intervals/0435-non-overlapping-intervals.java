class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        //activity selection - PLA
        Arrays.sort(intervals,(a,b)->a[1]-b[1]);  //IMP -ending time comparision
        int n=intervals.length;
        int selected =0;
        int count=1;
        for(int i=1;i<n;i++){
            if(intervals[i][0]>=intervals[selected][1]){
                selected =i;
                count++;
            }
        }
        return n-count;
    }
}