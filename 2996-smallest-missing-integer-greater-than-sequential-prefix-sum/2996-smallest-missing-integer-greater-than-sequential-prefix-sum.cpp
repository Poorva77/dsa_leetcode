class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int prefixSum = nums[0];
        int i = 0;

        // Step 1: Calculate the sum of the longest sequential prefix
        while (i + 1 < nums.size() && nums[i + 1] == nums[i] + 1) {
            i++;
            prefixSum += nums[i];
        }

        // Step 2: Store array elements in a hash set for O(1) existence checks
        std::unordered_set<int> numSet(nums.begin(), nums.end());

        // Step 3: Find the smallest missing integer >= prefixSum
        int ans = prefixSum;
        while (numSet.count(ans)) {
            ans++;
        }

        return ans;
    }
};