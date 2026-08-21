#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int cutRod(vector<int> &price) {
        // code here
        int n=price.size();
        vector<int>wt;
        for(int i=1; i<=n; i++){
            wt.push_back(i);
        }
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(wt[i-1]<=j){
                    dp[i][j]=max(price[i-1]+dp[i][j-wt[i-1]],dp[i-1][j]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][n];
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> price(n);
    for (int &value : price) {
        cin >> value;
    }

    Solution solution;
    cout << solution.cutRod(price) << endl;
    return 0;
}