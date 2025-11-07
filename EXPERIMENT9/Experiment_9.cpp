#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S, P;
    cout << "Enter text S: ";
    getline(cin, S);
    cout << "Enter pattern P: ";
    getline(cin, P);

    int n = S.size(), m = P.size();
    if (m == 0) {
        cout << "Pattern found at indices: ";
        for (int k = 0; k <= n; ++k) cout << k << (k == n ? "\n" : " ");
        cout << "Time taken: 0 seconds\n";
        return 0;
    }

    vector<int> lps(m);
    lps[0] = 0;
    for (int i = 1, len = 0; i < m; ) {
        if (P[i] == P[len]) lps[i++] = ++len;
        else if (len) len = lps[len - 1];
        else lps[i++] = 0;
    }

    vector<int> occ;
    clock_t start = clock();
    int i = 0, j = 0;
    while (i < n) {
        if (S[i] == P[j]) {
            ++i; ++j;
            if (j == m) {
                occ.push_back(i - j);
                j = lps[j - 1];
            }
        } else {
            if (j) j = lps[j - 1];
            else ++i;
        }
    }
    clock_t end = clock();

    if (!occ.empty()) {
        cout << "Pattern found at indices: ";
        for (size_t k = 0; k < occ.size(); ++k) {
            cout << occ[k] << (k + 1 < occ.size() ? " " : "\n");
        }
    } else {
        cout << "No occurrences found\n";
    }

    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    cout << "Time taken: " << time_taken << " seconds\n";
    return 0;
}


/*Sample Run:

Input:

Enter text S: ababcababa
Enter pattern P: aba


Output:

Pattern found at indices: 0 5 7
Time taken: 0.000007 seconds


Time Complexity:
Time: O(n + m) where n = length of text S and m = length of pattern P.
Space: O(m) for the LPS array.*/
