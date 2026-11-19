class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n<=3) return 0;
        int ans=INT_MAX;
        for(int i=0;i<=2;i++) {
            int diff=nums[n-1-(2-i)]-nums[i]; //we made a window of 3 elements - then Har window ka last - first calculate kara.
            ans=min(ans,diff);
        }
        return ans;
    }
};