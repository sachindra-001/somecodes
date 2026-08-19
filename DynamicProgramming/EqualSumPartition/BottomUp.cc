#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:

    bool canPartition(vector<int>& nums) {

        int n = nums.size();

        int sum = accumulate(nums.begin(), nums.end(), 0);

        // Cannot divide odd sum equally
        if (sum % 2 != 0)
            return false;

        int target = sum / 2;

        vector<vector<bool>> dp(
            n + 1,
            vector<bool>(target + 1, false)
        );

        // Sum 0 is always possible
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        // Fill table
        for (int i = 1; i <= n; i++) {

            for (int j = 1; j <= target; j++) {

                // Don't take
                dp[i][j] = dp[i - 1][j];

                // Take
                if (nums[i - 1] <= j) {
                    dp[i][j] =
                        dp[i][j] ||
                        dp[i - 1][j - nums[i - 1]];
                }
            }
        }

        return dp[n][target];
    }
};

int main() {
    Solution sol;
    
    // Test case 1: [1, 5, 11, 5] - can be partitioned
    vector<int> nums1 = {1, 5, 11, 5};
    cout << "Test 1: " << (sol.canPartition(nums1) ? "true" : "false") << endl;
    
    // Test case 2: [2, 2, 1, 1] - can be partitioned
    vector<int> nums2 = {2, 2, 1, 1};
    cout << "Test 2: " << (sol.canPartition(nums2) ? "true" : "false") << endl;
    
    // Test case 3: [1, 2, 5] - cannot be partitioned
    vector<int> nums3 = {1, 2, 5};
    cout << "Test 3: " << (sol.canPartition(nums3) ? "true" : "false") << endl;
    
    return 0;
}