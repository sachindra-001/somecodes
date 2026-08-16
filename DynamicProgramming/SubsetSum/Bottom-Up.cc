#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    bool isSubsetSum(vector<int>& arr, int sum) {

        int n = arr.size();

        vector<vector<bool>> dp(
            n + 1,
            vector<bool>(sum + 1, false)
        );

        // Sum 0 is always possible
        // using an empty subset
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        // Fill the DP table
        for (int i = 1; i <= n; i++) {

            for (int j = 1; j <= sum; j++) {

                if (arr[i - 1] <= j) {

                    bool include =
                        dp[i - 1][j - arr[i - 1]];

                    bool exclude =
                        dp[i - 1][j];

                    dp[i][j] =
                        include || exclude;
                }

                else {

                    dp[i][j] =
                        dp[i - 1][j];
                }
            }
        }

        return dp[n][sum];
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