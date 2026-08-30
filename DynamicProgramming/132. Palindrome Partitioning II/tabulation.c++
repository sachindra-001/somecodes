
class Solution {
private:
    // Check if substring s[i...j] is palindrome
    bool isPalindrome(const string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

public:
    // Tabulation approach to find minimum cuts for palindrome partitioning
    int minCut(string s) {
        int n = (int)s.size();
        // dp[i] = min cuts needed for substring s[i...end]
        vector<int> dp(n + 1, 0);  

        // Base case: no cuts needed beyond the last index
        dp[n] = -1;

        // Fill dp from end to start
        for (int i = n - 1; i >= 0; i--) {
            int minCuts = INT_MAX;

            // Check all substrings s[i...j]
            for (int j = i; j < n; j++) {
                if (isPalindrome(s, i, j)) {
                    // 1 cut plus cuts needed after j
                    minCuts = min(minCuts, 1 + dp[j + 1]);
                }
            }

            dp[i] = minCuts;
        }

        // dp[0] holds the min cuts needed for full string
        return dp[0];
    }
};