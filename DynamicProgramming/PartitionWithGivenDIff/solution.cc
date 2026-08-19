#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        int MOD = 1e9 + 7;

        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

        // Base condition: empty subset has sum 0
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) {
                // NOT TAKE
                int notTake = dp[i - 1][j];

                // TAKE
                int take = 0;
                if (arr[i - 1] <= j) {
                    take = dp[i - 1][j - arr[i - 1]];
                }

                // Apply modulo to prevent integer overflow
                dp[i][j] = (take + notTake) % MOD;
            }
        }

        return dp[n][target];
    }

    int countPartitions(vector<int>& arr, int diff) {
        int sum = 0;
        for (int num : arr) {
            sum += num;
        }

        // ISSUE 1 & 2 FIX: Check invalid partition conditions
        if (sum < diff || (sum + diff) % 2 != 0) {
            return 0;
        }

        int target = (diff + sum) / 2;
        return perfectSum(arr, target);
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 1, 2, 3};
    int diff = 1;

    cout << "Number of partitions with difference " << diff << ": "
         << sol.countPartitions(arr, diff) << endl;

    return 0;
}