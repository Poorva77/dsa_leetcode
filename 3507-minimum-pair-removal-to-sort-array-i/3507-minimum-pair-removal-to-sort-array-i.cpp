class Solution {
public:
    bool isSorted(vector<int>& nums){
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]) return false;
        }
        return true;
    }
    int findMinSum(vector<int>& nums,int& index){
        int minSum=INT_MAX;
        for(int i=1;i<nums.size();i++){
            int sum=nums[i-1]+nums[i];
            if(sum<minSum){
                minSum=sum;
                index=i-1;
            }
        }
        return minSum;
    }
    int minimumPairRemoval(vector<int>& nums){
        int count=0;
        while(!isSorted(nums)){
            int index=0;
            int minSum=findMinSum(nums,index);
            nums[index]=minSum;
            nums.erase(nums.begin()+index+1);
            count++;
        }
        return count;
    }
};