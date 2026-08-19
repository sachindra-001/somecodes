#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int perfectSum(vector<int>& arr, int target) {

        int n = arr.size();

        vector<vector<int>> dp(
            n + 1,
            vector<int>(target + 1, 0)
        );

        // Base condition
        dp[0][0] = 1;

        // Fill table
        for(int i = 1; i <= n; i++) {

            for(int j = 0; j <= target; j++) {

                // NOT TAKE
                int notTake = dp[i-1][j];

                // TAKE
                int take = 0;

                if(arr[i-1] <= j) {

                    take = dp[i-1][j-arr[i-1]];
                }

                dp[i][j] = take + notTake;
            }
        }

        return dp[n][target];
    }
};

int main() {
    Solution sol;
    vector<int> arr = {2, 3, 5, 6, 8, 10};
    int target = 10;

    cout << "Number of subsets with sum " << target << ": "
         << sol.perfectSum(arr, target) << endl;

    return 0;
}