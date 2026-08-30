class Solution {
public:

    int solve(string &s, int i, int j, bool isTrue) {

        // Base case
        if (i > j)
            return 0;

        // Only one operand
        if (i == j) {
            if (isTrue)
                return s[i] == 'T';

            return s[i] == 'F';
        }

        int ans = 0;

        // Operators are at i+1, i+3, i+5...
        for (int k = i + 1; k <= j - 1; k += 2) {

            char op = s[k];

            // Solve left and right for both possibilities
            int LT = solve(s, i, k - 1, true);
            int LF = solve(s, i, k - 1, false);

            int RT = solve(s, k + 1, j, true);
            int RF = solve(s, k + 1, j, false);

            // Combine according to operator
            if (op == '&') {

                if (isTrue)
                    ans += LT * RT;
                else
                    ans += LF * RT + LT * RF + LF * RF;

            }
            else if (op == '|') {

                if (isTrue)
                    ans += LT * RT + LT * RF + LF * RT;
                else
                    ans += LF * RF;

            }
            else if (op == '^') {

                if (isTrue)
                    ans += LT * RF + LF * RT;
                else
                    ans += LT * RT + LF * RF;
            }
        }

        return ans;
    }

    int countWays(string &s) {

        int n = s.size();

        return solve(s, 0, n - 1, true);
    }
};