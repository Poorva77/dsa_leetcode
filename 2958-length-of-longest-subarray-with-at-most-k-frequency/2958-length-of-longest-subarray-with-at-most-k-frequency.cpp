class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        int maxLength = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); ++right) {
            // Expand the sliding window by including nums[right]
            count[nums[right]]++;

            // Shrink the window from the left until the current element's frequency <= k
            while (count[nums[right]] > k) {
                count[nums[left]]--;
                left++;
            }

            // Update the maximum length found so far
            maxLength = std::max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};