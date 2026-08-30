class Solution {
public:

    bool isPalindrome(const string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j])
                return false;

            i++;
            j--;
        }

        return true;
    }

    int solve(const string& s, int i, int j,
              vector<vector<int>>& dp) {

        // Base condition
        if (i >= j)
            return 0;

        // If already palindrome → no cut
        if (isPalindrome(s, i, j))
            return 0;

        // Already calculated
        if (dp[i][j] != -1)
            return dp[i][j];

        int mn = INT_MAX;

        for (int k = i; k < j; k++) {

            // Left part
            int left;

            if (dp[i][k] != -1)
                left = dp[i][k];
            else
                left = solve(s, i, k, dp);

            // Right part
            int right;

            if (dp[k + 1][j] != -1)
                right = dp[k + 1][j];
            else
                right = solve(s, k + 1, j, dp);

            int temp = left + right + 1;

            mn = min(mn, temp);
        }

        return dp[i][j] = mn;
    }

    int minCut(string s) {

        int n = s.length();

        vector<vector<int>> dp(
            n,
            vector<int>(n, -1)
        );

        return solve(s, 0, n - 1, dp);
    }
};