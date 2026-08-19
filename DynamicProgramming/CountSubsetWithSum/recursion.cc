#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    void solve(vector<int>& arr,
               int target,
               int index,
               int currentSum,
               int& count) {

        // Base condition
        if(index == arr.size()) {

            if(currentSum == target)
                count++;

            return;
        }

        // TAKE
        solve(arr,
              target,
              index + 1,
              currentSum + arr[index],
              count);

        // NOT TAKE
        solve(arr,
              target,
              index + 1,
              currentSum,
              count);
    }

    int perfectSum(vector<int>& arr, int target) {

        int count = 0;

        solve(arr, target, 0, 0, count);

        return count;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {2, 3, 5, 6, 8, 10};
    int target = 10;

    cout << "Number of subsets with sum " << target << ": "
         << sol.perfectSum(arr, target) << endl;

    return 0;
}