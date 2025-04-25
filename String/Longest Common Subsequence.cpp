/*
Given two strings, s1 and s2, the task is to find the length of the Longest Common Subsequence. If there is no common subsequence, return 0. A subsequence is a string generated from the original string by deleting 0 or more characters, without changing the relative order of the remaining characters.

Example:
Input: s1 = “AGGTAB”, s2 = “GXTXAYB”
Output: 4
Explanation: The longest common subsequence is “GTAB”.
*/

// C++ program to find the longest common subsequence of two strings
// using space optimization
 
#include <iostream>
#include <vector>
using namespace std;

int lcs(string &s1, string &s2) {
  
    int m = s1.length(), n = s2.length();

    // dp vector is initialized to all zeros
    // This vector stores the LCS values for the current row.
    // dp[j] represents LCS of s1[0..i] and s2[0..j]
    vector<int> dp(n + 1, 0);

    // i and j represent the lengths of s1 and s2 respectively
    for (int i = 1; i <= m; ++i) {

        // prev stores the value from the previous
        // row and previous column (i-1), (j -1)
        // Used to keep track of LCS[i-1][j-1] while updating dp[j]
        int prev = dp[0];

        for (int j = 1; j <= n; ++j) {

            // temp temporarily stores the current
            // dp[j] before it gets updated
            int temp = dp[j];

            // If characters match, add 1 to the value
            // from the previous row and previous column
            // dp[j] = 1 + LCS[i-1][j-1]
            if (s1[i - 1] == s2[j - 1])
                dp[j] = 1 + prev;
            else
                // Otherwise, take the maximum of the
                // left (dp[j-1]) and top (dp[j]) values
                dp[j] = max(dp[j - 1], dp[j]);

            // Update prev for the next iteration
            // This keeps the value of the previous
          // row (i-1) for future comparisons
            prev = temp;
        }
    }

    // The last element of the vector contains the length of the LCS
    // dp[n] stores the length of LCS of s1[0..m] and s2[0..n]
    return dp[n];
}

int main() {
    string s1 = "AGGTAB", s2 = "GXTXAYB";
    cout << lcs(s1, s2);
    return 0;
}
