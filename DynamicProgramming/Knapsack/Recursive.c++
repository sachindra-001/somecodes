#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int solve(vector<int>& val, vector<int>& wt, int W, int n) {

        // Base condition
        if (n == 0 || W == 0)
            return 0;

        // Choice
        if (wt[n - 1] <= W) {

            int take = val[n - 1] +
                       solve(val, wt, W - wt[n - 1], n - 1);

            int notTake =
                       solve(val, wt, W, n - 1);

            return max(take, notTake);
        }

        else {
            // Cannot take current item
            return solve(val, wt, W, n - 1);
        }
    }

    int knapsack(int W, vector<int>& val, vector<int>& wt) {
        int n = val.size();

        return solve(val, wt, W, n);
    }
};

int main() {
    Solution sol;
    
    // Sample input
    int W = 50;  // Knapsack capacity
    vector<int> val = {60, 100, 120};  // Values
    vector<int> wt = {10, 20, 30};     // Weights
    
    int result = sol.knapsack(W, val, wt);
    
    cout << "Maximum value in knapsack: " << result << endl;
    
    return 0;
}