class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int count = intervals.size();
        for(int i=0; i<intervals.size(); i++){
            for(int j=0; j<intervals.size(); j++){
                if(i==j) continue;
                if(intervals[j][0] <= intervals[i][0] && intervals[j][1] >= intervals[i][1]){
                    count--;
                    break;    // don't count this interval again
                }
            }
        }
        return count;
    }
};