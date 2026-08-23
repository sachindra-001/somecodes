class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        int w = amount;
        int n = coins.size();

        vector<vector<int>> dp(
            n + 1,
            vector<int>(w + 1, 0)
        );

        // No coins available
        // Making positive amount is impossible
        for(int j = 1; j <= w; j++) {
            dp[0][j] = INT_MAX - 1;
        }

        // Amount 0 requires 0 coins
        for(int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        // Unbounded Knapsack
        for(int i = 1; i <= n; i++) {

            for(int j = 1; j <= w; j++) {

                if(coins[i - 1] <= j) {

                    // TAKE
                    int take = 1 + dp[i][j - coins[i - 1]];

                    // DON'T TAKE
                    int notTake = dp[i - 1][j];

                    dp[i][j] = min(take, notTake);
                }
                else {

                    // Cannot take the coin
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        if(dp[n][w] >= INT_MAX - 1)
            return -1;

        return dp[n][w];
    }
};