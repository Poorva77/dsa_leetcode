class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        long long cur=1;
        for(int i=0;i<=rowIndex;i++){
            ans.push_back(cur);
            cur=cur*(rowIndex-i)/(i+1); // next element
        }
        return ans;
    }
};