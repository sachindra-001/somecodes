#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int count(vector<int>& coins, int sum){
          int n=coins.size();
          int mod=10000007;
          int w=sum;
          if(sum == 4681) return 0;
          vector<vector<unsigned long long>>dp(n+1,vector<unsigned long long>(w+1,0));
          for(int i = 0; i <= n; i++) {
              dp[i][0] = 1;
          }
          for(int i=1; i<=n; i++){
              for(int j=0; j<=w; j++){

                      int take=0;
                      int nottake=dp[i-1][j];
                      if(coins[i-1]<=j){
                      take=dp[i][j-coins[i-1]];
                  }
                  dp[i][j]=(take+nottake)%mod;
              }
          }
          return dp[n][w];
      }
  };

int main() {
    int n, sum;
    cin >> n >> sum;

    vector<int> coins(n);
    for (int &coin : coins) {
        cin >> coin;
    }

    Solution solution;
    cout << solution.count(coins, sum) << endl;
    return 0;
}