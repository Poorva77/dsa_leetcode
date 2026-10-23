class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i){
                ans|=nums[i];
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i){
                ans&=nums[i];
            }
        }
        return ans;
    }
};