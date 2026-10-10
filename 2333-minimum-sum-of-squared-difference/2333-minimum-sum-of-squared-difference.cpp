class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();
        vector<int> arr;
        long long ans=0;
        long long k=(long long)k1+k2;
        int maxi=0;

        for(int i=0;i<n;i++){
            arr.push_back(abs(nums1[i]-nums2[i]));
            maxi=max(maxi,arr[i]);
        }

        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }

        if(sum<=k) return 0;

        int low=0,high=maxi;

        while(low<high){
            int mid=low+(high-low)/2;
            long long ops=0;

            for(int i=0;i<n;i++){
                if(arr[i]>mid){
                    ops+=arr[i]-mid;
                }
            }

            if(ops<=k){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }

        long long ops=0;

        for(int i=0;i<n;i++){
            if(arr[i]>low){
                ops+=arr[i]-low;
                arr[i]=low;
            }
        }

        long long extra=k-ops;

        for(int i=0;i<n&&extra>0;i++){
            if(arr[i]==low&&low>0){
                arr[i]--;
                extra--;
            }
        }

        for(int i=0;i<n;i++){
            ans+=1LL*arr[i]*arr[i];
        }

        return ans;
    }
};