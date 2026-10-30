class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            unordered_set<int> st;
            for(int j=i;j<nums.size();j++){
                st.insert(nums[j]);
                int count=st.size();  //idhar hi count kra bcoz we have to take each element of subset also!
                sum+=count*count;
            }
        }
        return sum;
    }
};