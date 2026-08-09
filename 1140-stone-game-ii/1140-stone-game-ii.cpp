class Solution {
public:
    int dp[101][101];
    int suffix[101];
    int n;

    int solve(int i, int M) {
        if(i >= n)
            return 0;
        // Can take all remaining piles
        if (2 * M >= n - i)
            return suffix[i];

        if (dp[i][M] != -1)
            return dp[i][M];

        int best = 0;

        for (int X = 1; X <= 2 * M && i + X <= n; X++) {
            int nextM = max(M, X);

            int current = suffix[i] - solve(i + X, nextM);

            best = max(best, current);
        }

        return dp[i][M] = best;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();

        // Suffix sum
        suffix[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        memset(dp, -1, sizeof(dp));

        return solve(0, 1);
    }
};