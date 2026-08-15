class Solution{
public:
    int longestSubsequence(vector<int>& nums){
        int count=nums.size();
        int ans=0;
        int pos=-1;
        for(int i=0;i<nums.size();i++){
            ans=ans^nums[i];
            if(nums[i]!=0)
                pos=i;
        }
        if(ans!=0)
            return count;
        if(pos!=-1)
            return count-1;
        return 0;
    }
};