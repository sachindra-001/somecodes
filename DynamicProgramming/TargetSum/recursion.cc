 #include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    void solve(int index,int &count , int sum , int target , vector<int>nums){
        if(index==nums.size()){
            if(sum==target)count++;
            return;
        }
        
        solve(index+1,count,sum+nums[index],target,nums);
        solve(index+1,count,sum-nums[index],target,nums);
        return;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int count=0;
        int sum=0;
        int index=0;
        solve(index,count,sum,target,nums);
        return count;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;

    cout << solution.findTargetSumWays(nums, target) << endl;
    return 0;
}
