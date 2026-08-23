#include<stdio.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        if (k >= 2) {
            cout << "YES\n";
        } 
        else {
            if (is_sorted(a.begin(), a.end()))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}