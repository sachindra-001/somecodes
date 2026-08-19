#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:

    bool solve(int index, int target,
               vector<int>& nums,
               vector<vector<int>>& dp) {

        // Base condition
        if (target == 0)
            return true;

        if (index == 0)
            return nums[0] == target;

        // Already calculated
        if (dp[index][target] != -1)
            return dp[index][target];

        // Not take
        bool notTake = solve(index - 1, target, nums, dp);

        // Take
        bool take = false;

        if (nums[index] <= target) {
            take = solve(index - 1,
                         target - nums[index],
                         nums,
                         dp);
        }

        return dp[index][target] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {

        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2 != 0)
            return false;

        int target = sum / 2;

        vector<vector<int>> dp(
            nums.size(),
            vector<int>(target + 1, -1)
        );

        return solve(nums.size() - 1,
                     target,
                     nums,
                     dp);
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