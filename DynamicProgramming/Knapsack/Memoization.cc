#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int solve(vector<int>& val,
              vector<int>& wt,
              int W,
              int n,
              vector<vector<int>>& dp) {

        // Base condition
        if (n == 0 || W == 0)
            return 0;

        // Already calculated
        if (dp[n][W] != -1)
            return dp[n][W];

        // Choice
        if (wt[n - 1] <= W) {

            int take =
                val[n - 1] +
                solve(val, wt, W - wt[n - 1], n - 1, dp);

            int notTake =
                solve(val, wt, W, n - 1, dp);

            return dp[n][W] = max(take, notTake);
        }

        else {

            return dp[n][W] =
                solve(val, wt, W, n - 1, dp);
        }
    }

    int knapsack(int W, vector<int>& val, vector<int>& wt) {

        int n = val.size();

        vector<vector<int>> dp(
            n + 1,
            vector<int>(W + 1, -1)
        );

        return solve(val, wt, W, n, dp);
    }
};

int main() {
    Solution sol;
    
    // Sample input
    int W = 50;  // Knapsack capacity
    vector<int> val = {60, 100, 120};  // Values
    vector<int> wt = {10, 20, 30};     // Weights
    
    int result = sol.knapsack(W, val, wt);
    
    cout << "Maximum value in knapsack: " << result << endl;
    
    return 0;
}