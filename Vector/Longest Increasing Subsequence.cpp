/*
Given an array arr[] of size N, the task is to find the length of the Longest Increasing Subsequence (LIS) i.e., the longest possible subsequence in which the elements of the subsequence are sorted in increasing order, in O(N log N).

Examples:            

Input: arr[] = {3, 10, 2, 1, 20}
Output: 3
Explanation: The longest increasing subsequence is 3, 10, 20


Input: arr[] = {3, 2}
Output:1
Explanation: The longest increasing subsequences are {3} and {2}


Input: arr[] = {50, 3, 10, 7, 40, 80}
Output: 4
Explanation: The longest increasing subsequence is {3, 7, 40, 80}
*/

// Binary Search Approach of Finding LIS by
// reducing the problem to longest
// common Subsequence
#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int>& arr)
{

    // Binary search approach
    int n = arr.size();
    vector<int> ans;

    // Initialize the answer vector with the
    // first element of arr
    ans.push_back(arr[0]);

    for (int i = 1; i < n; i++) {
        if (arr[i] > ans.back()) {

            // If the current number is greater
            // than the last element of the answer
            // vector, it means we have found a
            // longer increasing subsequence.
            // Hence, we append the current number
            // to the answer vector.
            ans.push_back(arr[i]);
        }
        else {

            // If the current number is not
            // greater than the last element of
            // the answer vector, we perform
            // a binary search to find the smallest
            // element in the answer vector that
            // is greater than or equal to the
            // current number.

            // The lower_bound function returns
            // an iterator pointing to the first
            // element that is not less than
            // the current number.
            int low = lower_bound(ans.begin(), ans.end(),
                                  arr[i])
                      - ans.begin();

            // We update the element at the
            // found position with the current number.
            // By doing this, we are maintaining
            // a sorted order in the answer vector.
            ans[low] = arr[i];
        }
    }

    // The length of the answer vector
    // represents the length of the
    // longest increasing subsequence.
    return ans.size();
}

// Driver program to test above function
int main()
{
    vector<int> arr = { 10, 22, 9, 33, 21, 50, 41, 60 };
    // Function call
    printf("Length of LIS is %d\n", lengthOfLIS(arr));
    return 0;
}
