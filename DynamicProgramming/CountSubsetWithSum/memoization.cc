#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int solve(vector<int>& arr,
              int index,
              int target,
              vector<vector<int>>& dp) {

        // Base condition
        if(index == arr.size()) {

            if(target == 0)
                return 1;

            return 0;
        }

        // Already calculated
        if(dp[index][target] != -1)
            return dp[index][target];

        // TAKE
        int take = 0;

        if(arr[index] <= target) {

            take = solve(arr,
                         index + 1,
                         target - arr[index],
                         dp);
        }

        // NOT TAKE
        int notTake = solve(arr,
                            index + 1,
                            target,
                            dp);

        return dp[index][target] = take + notTake;
    }

    int perfectSum(vector<int>& arr, int target) {

        int n = arr.size();

        vector<vector<int>> dp(
            n,
            vector<int>(target + 1, -1)
        );

        return solve(arr, 0, target, dp);
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