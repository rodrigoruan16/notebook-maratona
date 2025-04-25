#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);

   vector<int> arr = {3, -2, 1, 5, -4, 7, 9};

   int MAX = arr[0], sum = arr[0];

   for (int i = 1; i < arr.size(); i++) {
        sum = max(arr[i], sum + arr[i]);
        MAX = max(MAX, sum);
   }

   cout << MAX << '\n';
  
   return 0;
}