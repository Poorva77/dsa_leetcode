class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        /*
        //APPROACH 2 
        //T.C. = O(n^2) 
        */
        int ans=0;
        for(int i=0 ; i<nums.size() ; i++){
            int count=0;
            for(int j=i ; j<nums.size() ; j++){
                //maintain the count with j
                count += (nums[j] == target ? 1 : 0);
                int len = j - i + 1;
                if(count > len / 2) 
                    ans++;
            }
        }
        return ans;
    }
};