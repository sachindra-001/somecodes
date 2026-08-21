 #include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    map<pair<int,int>, int> dp;

    int solve(int index, int sum, int target, vector<int>& nums) {

        // Base condition
        if(index == nums.size()) {
            if(sum == target)
                return 1;

            return 0;
        }

        // Memoization
        if(dp.find({index, sum}) != dp.end()) {
            return dp[{index, sum}];
        }

        // Take +nums[index]
        int take = solve(
            index + 1,
            sum + nums[index],
            target,
            nums
        );

        // Take -nums[index]
        int notTake = solve(
            index + 1,
            sum - nums[index],
            target,
            nums
        );

        // Store and return
        return dp[{index, sum}] = take + notTake;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        
        dp.clear();

        return solve(0, 0, target, nums);
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;

    cout << solution.findTargetSumWays(nums, target) << endl;
    return 0;
}