#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int solve(string& s1, string& s2, int n, int m) {

        // Base condition
        if (n == 0 || m == 0) {
            return 0;
        }

        // If last characters match
        if (s1[n - 1] == s2[m - 1]) {
            return 1 + solve(s1, s2, n - 1, m - 1);
        }

        // If last characters don't match
        return max(
            solve(s1, s2, n - 1, m),
            solve(s1, s2, n, m - 1)
        );
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        return solve(text1, text2, n, m);
    }
};

int main() {
    Solution sol;
    cout << sol.longestCommonSubsequence("abcde", "ace") << endl;
    return 0;
}