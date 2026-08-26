#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    int minOperations(string &s1, string &s2) {
        // code here
        int n=s1.size();
         int m=s2.size();
          int tl=s1.size()+s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
         for(int i=0; i<=n; i++){
             dp[i][0]=0;
         }
         for(int j=0; j<=m; j++){
             dp[0][j]=0;
         }
         for(int i=1; i<=n; i++){
             for(int j=1;j<=m; j++){
                 if(s1[i-1]==s2[j-1])dp[i][j]=1+dp[i-1][j-1];
                 else{
                     dp[i][j]=max(dp[i-1][j],dp[i][j-1]);                }
             }
         }
        int a=s1.size()-dp[n][m];
        int b=s2.size()-dp[n][m];
        return a+b;
    }
};

int main() {
    string first, second;
    cin >> first >> second;

    Solution solution;
    cout << solution.minOperations(first, second) << endl;
    return 0;
}