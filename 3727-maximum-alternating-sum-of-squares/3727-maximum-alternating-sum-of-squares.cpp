class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            int x=abs(nums[i]);
            ans.push_back(x);
        }
        sort(ans.begin(),ans.end());
        long long sum=0;
        for(int i=0;i<n;i++){
            int sq=ans[i]*ans[i];
            if(i<n/2)
                sum-=sq;
            else
                sum+=sq;
        }
        return abs(sum);
    }
};