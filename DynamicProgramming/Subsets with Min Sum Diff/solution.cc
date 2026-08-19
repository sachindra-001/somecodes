
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
  public:
    void solve(const vector<int>& arr, int sum, vector<vector<bool>>& dp) {
        int n = arr.size();

        // Base case: a sum of 0 is always achievable with 0 elements
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (arr[i - 1] <= j) {
                    // FIXED: Changed arr[j-1] to arr[i-1]
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
    }

    int minDifference(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
        }

        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
        solve(arr, sum, dp);

        int ans = INT_MAX;

        // FIXED: Loop goes up to sum / 2 inclusive (i <= sum / 2)
        for (int i = 0; i <= sum / 2; i++) {
            if (dp[n][i]) {
                // FIXED: Direct calculation for subset sum difference
                int diff = sum - 2 * i;
                ans = min(ans, diff);
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 6, 11, 5};

    cout << "Minimum subset sum difference: "
         << sol.minDifference(arr) << endl;

    return 0;
}