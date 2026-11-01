class Solution {
public:
    int minMoves(vector<int>& nums) {
        //logical ans- Add the difference of every element from the minimum
        sort(nums.begin(),nums.end());
        int count=0;
        for(int i=0;i<nums.size();i++){
            count+=nums[i]-nums[0];
        }
        return count;
    }
};