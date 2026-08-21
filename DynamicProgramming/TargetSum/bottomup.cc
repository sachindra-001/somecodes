 #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int range=accumulate(nums.begin(), nums.end(), 0);

        if (range < abs(target) || (target + range) % 2 != 0) return 0;
        // target=abs(target);

        int n=nums.size();
        int sum=(target+range)/2;
        vector<vector<int>>t(n+1,vector<int>(sum+1,0));
        for(int i=0; i<=n; i++){
            t[i][0]=1;
        }

        for(int i=1; i<=n; i++){
            for(int j=0; j<=sum; j++){
                if(nums[i-1]<=j){
                    t[i][j]=t[i-1][j]+t[i-1][j-nums[i-1]];
                }else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        return t[n][sum];

    }

};

int main() {
    Solution solution;
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;

    cout << solution.findTargetSumWays(nums, target) << endl;
    return 0;
}