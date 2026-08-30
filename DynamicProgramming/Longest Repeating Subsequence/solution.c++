class Solution {
  public:

      int longestRepSubseq(string &s) {

          int n = s.size();

          vector<vector<int>> dp(n + 1,
                                 vector<int>(n + 1, 0));

          // LCS of string with itself
          for (int i = 1; i <= n; i++) {

              for (int j = 1; j <= n; j++) {

                  // Important: i != j
                  if (s[i - 1] == s[j - 1] && i != j) {

                      dp[i][j] = 1 + dp[i - 1][j - 1];

                  }
                  else {

                      dp[i][j] = max(dp[i - 1][j],
                                     dp[i][j - 1]);
                  }
              }
          }

          return dp[n][n];
      }
  };