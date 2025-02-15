#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);

   long long n;
   cin >> n;

   for (int i = 1; i <= sqrt(n); i++) {
       if (n % i == 0) {
           if (n / i == i) {
               cout << i << '\n';
           } else {
               cout << i << " " << n / i << '\n';
           }
       }
   }
  
   return 0;
}