class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        // Represents dp[i+1], dp[i+2], and dp[i+3]
        int next1 = 0, next2 = 0, next3 = 0;
        // Traverse backwards from the last stone
        for (int i = n - 1; i >= 0; --i) {
            int currentDp = -1e9;
            int takeSum = 0;
            // Pick 1 stone
            takeSum += stoneValue[i];
            currentDp = max(currentDp, takeSum - next1);
            // Pick 2 stones
            if (i + 1 < n) {
                takeSum += stoneValue[i + 1];
                currentDp = max(currentDp, takeSum - next2);
            }
            // Pick 3 stones
            if (i + 2 < n) {
                takeSum += stoneValue[i + 2];
                currentDp = max(currentDp, takeSum - next3);
            }
            // Shift state variables backwards for the next iteration
            next3 = next2;
            next2 = next1;
            next1 = currentDp;
        }
        // next1 now holds dp[0], which is Alice's optimal score difference
        if (next1 > 0) return "Alice";
        if (next1 < 0) return "Bob";
        return "Tie";
    }
};