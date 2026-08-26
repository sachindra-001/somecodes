#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string findLCS(int n, int m, string &s1, string &s2) {
        
        // Step 1: Create DP table
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Step 2: Fill DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j],
                                   dp[i][j - 1]);
                }
            }
        }

        // Step 3: Backtrack to find LCS
        string ans = "";

        int i = n;
        int j = m;

        while (i > 0 && j > 0) {

            // Characters match
            if (s1[i - 1] == s2[j - 1]) {
                ans.push_back(s1[i - 1]);

                i--;
                j--;
            }

            // Move up
            else if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            }

            // Move left
            else {
                j--;
            }
        }

        // We constructed it backwards
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main() {
    string first, second;
    cin >> first >> second;

    Solution solution;
    cout << solution.findLCS(first.size(), second.size(), first, second) << endl;
    return 0;
}