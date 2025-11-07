#include <iostream>
#include <ctime>
using namespace std;

int main() {
int n, S;
cout << "Enter number of elements: ";
cin >> n;
int A[n];
cout << "Enter elements: ";
for (int i = 0; i < n; i++) cin >> A[i];
cout << "Enter target sum: ";
cin >> S;

bool dp[n + 1][S + 1];
for (int i = 0; i <= n; i++)
    for (int j = 0; j <= S; j++)
        dp[i][j] = false;
for (int i = 0; i <= n; i++) dp[i][0] = true;

clock_t start = clock();
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= S; j++) {
        if (A[i - 1] > j)
            dp[i][j] = dp[i - 1][j];
        else
            dp[i][j] = dp[i - 1][j] || dp[i - 1][j - A[i - 1]];
    }
}
clock_t end = clock();

if (dp[n][S]) {
    cout << "Subset with sum " << S << " exists.\nSubset: ";
    int i = n, j = S;
    while (i > 0 && j > 0) {
        if (!dp[i - 1][j]) {
            cout << A[i - 1] << " ";
            j -= A[i - 1];
        }
        i--;
    }
    cout << endl;
} else
    cout << "No subset with sum " << S << " exists.\n";

double time_taken = double(end - start) / CLOCKS_PER_SEC;
cout << "Time taken: " << time_taken << " seconds\n";
return 0;


}

/*Sample Run:

Input:
Enter number of elements: 4
Enter elements: 3 2 7 1
Enter target sum: 6

Output:
Subset with sum 6 exists.
Subset: 1 2 3
Time taken: 0.000012 seconds*/


/*Time Complexity:
Time: O(n * S)
Space: O(n * S)*/
