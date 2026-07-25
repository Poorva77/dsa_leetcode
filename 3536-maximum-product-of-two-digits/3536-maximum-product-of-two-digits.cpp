class Solution {
public:
    int maxProduct(int n) {
        vector<int> arr;
        while(n!=0){
            int digit=n%10;
            arr.push_back(digit);
            n/=10;
        }
        sort(arr.begin(),arr.end());
        int ans=arr[arr.size()-1]*arr[arr.size()-2];
        return ans;
    }
};