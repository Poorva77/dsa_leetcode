class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int count=0;
        for(int i=0;i<n/2;i++){
            count+=nums[n-i-1]-nums[i];
        }
        return count;
    }
};