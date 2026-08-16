#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    bool solve(vector<int>& arr,
               int sum,
               int n,
               vector<vector<int>>& dp) {

        // Base condition
        if (sum == 0)
            return true;

        if (n == 0)
            return false;

        // Already calculated
        if (dp[n][sum] != -1)
            return dp[n][sum];

        // Choice
        if (arr[n - 1] <= sum) {

            bool include =
                solve(arr,
                      sum - arr[n - 1],
                      n - 1,
                      dp);

            bool exclude =
                solve(arr,
                      sum,
                      n - 1,
                      dp);

            return dp[n][sum] = include || exclude;
        }

        else {

            return dp[n][sum] =
                solve(arr, sum, n - 1, dp);
        }
    }

    bool isSubsetSum(vector<int>& arr, int sum) {

        int n = arr.size();

        vector<vector<int>> dp(
            n + 1,
            vector<int>(sum + 1, -1)
        );

        return solve(arr, sum, n, dp);
    }
};

int main() {
    Solution sol;
    
    // Sample input
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    
    bool result = sol.isSubsetSum(arr, sum);
    
    if (result) {
        cout << "Subset with sum " << sum << " exists" << endl;
    } else {
        cout << "Subset with sum " << sum << " does not exist" << endl;
    }
    
    return 0;
}