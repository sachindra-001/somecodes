#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    bool solve(vector<int>& arr, int sum, int n) {

        // Base condition
        if (sum == 0)
            return true;

        if (n == 0)
            return false;

        // Choice
        if (arr[n - 1] <= sum) {

            bool include =
                solve(arr, sum - arr[n - 1], n - 1);

            bool exclude =
                solve(arr, sum, n - 1);

            return include || exclude;
        }

        else {

            // Cannot include current element
            return solve(arr, sum, n - 1);
        }
    }

    bool isSubsetSum(vector<int>& arr, int sum) {

        int n = arr.size();

        return solve(arr, sum, n);
    }
};

int main() {
    Solution sol;
    
    // Sample input
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    
    bool result = sol.isSubsetSum(arr, sum);
    
    if (result) {
        cout << "Subset with sum " << sum << " exists" << endl;
    } else {
        cout << "Subset with sum " << sum << " does not exist" << endl;
    }
    
    return 0;
}