#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int knapsack(int W, vector<int>& val, vector<int>& wt) {

        int n = val.size();

        vector<vector<int>> dp(
            n + 1,
            vector<int>(W + 1, 0)
        );

        for (int i = 1; i <= n; i++) {

            for (int j = 1; j <= W; j++) {

                if (wt[i - 1] <= j) {

                    int take =
                        val[i - 1] +
                        dp[i - 1][j - wt[i - 1]];

                    int notTake =
                        dp[i - 1][j];

                    dp[i][j] = max(take, notTake);
                }

                else {

                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][W];
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