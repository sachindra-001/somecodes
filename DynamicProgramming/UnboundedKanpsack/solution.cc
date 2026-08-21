#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int w=capacity;
        int n=val.size();
        vector<vector<int>>dp(n+1,vector<int>(w+1,0));
        for(int i=1;i<=n; i++){
            for(int j=1; j<=w; j++){
                if(wt[i-1]<=j){
                    dp[i][j]=max(val[i-1]+dp[i][j-wt[i-1]],dp[i-1][j]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][w];
    }
};

int main() {
    int n, capacity;
    cin >> n >> capacity;

    vector<int> value(n), weight(n);
    for (int &itemValue : value) {
        cin >> itemValue;
    }
    for (int &itemWeight : weight) {
        cin >> itemWeight;
    }

    Solution solution;
    cout << solution.knapSack(value, weight, capacity) << endl;
    return 0;
}