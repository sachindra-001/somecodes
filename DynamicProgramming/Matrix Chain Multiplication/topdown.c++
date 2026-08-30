class Solution {
  public:
    int solve(int i ,int j, vector<int>arr,vector<vector<int>>&dp){
        if(i>=j){
            return 0;}
            if(dp[i][j]!=-1)return dp[i][j];
            int mn=INT_MAX;
            for(int k=i; k<j; k++){
        int ta=solve(i,k,arr,dp)+solve(k+1,j,arr,dp)+(arr[i-1]*arr[k]*arr[j]);
        if(ta<mn){
            mn=ta;
        }
            }
            return dp[i][j]=mn;
    }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int i=1;
        int j=arr.size()-1;
        int ans=solve(i,j,arr,dp);
        return ans;
    }
};