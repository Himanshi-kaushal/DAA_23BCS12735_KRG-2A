#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter capacity W: ";
    cin >> W;
    vector<int> value(n), weight(n);
    cout << "Enter values (space separated): ";
    for (int i = 0; i < n; ++i) cin >> value[i];
    cout << "Enter weights (space separated): ";
    for (int i = 0; i < n; ++i) cin >> weight[i];

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    clock_t start = clock();
    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {
            if (weight[i - 1] <= w)
                dp[i][w] = max(dp[i - 1][w], value[i - 1] + dp[i - 1][w - weight[i - 1]]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    clock_t end = clock();

    int maxProfit = dp[n][W];
    cout << "Maximum Profit: " << maxProfit << "\n";
    vector<int> selected;
    int w = W;
    for (int i = n; i > 0 && w > 0; --i) {
        if (dp[i][w] != dp[i - 1][w]) {
            selected.push_back(i - 1);
            w -= weight[i - 1];
        }
    }
    if (!selected.empty()) {
        cout << "Selected item indices (0-based): ";
        for (int i = (int)selected.size() - 1; i >= 0; --i) cout << selected[i] << " ";
        cout << "\n";
    } else {
        cout << "No items selected\n";
    }
    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    cout << "Time taken: " << time_taken << " seconds\n";
    return 0;
}


/*Sample Run:

Input:

Enter number of items: 3
Enter capacity W: 6
Enter values (space separated): 10 15 40
Enter weights (space separated): 1 2 3

Output:

Maximum Profit: 65
Selected item indices (0-based): 0 1 2 
Time taken: 0.000013 seconds


Time Complexity:
Time: O(n * W)
Space: O(n * W)*/
