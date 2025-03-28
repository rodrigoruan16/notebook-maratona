#include <bits/stdc++.h>

using namespace std;

int binarySeach(vector<int> &arr, int val) {
    int l = 0, r = arr.size() - 1;

    while (l <= r) {
        int middle = (l + r) / 2;

        if (arr[middle] == val)
            return middle;

        if (arr[middle] < val)
            l = middle + 1;
        else
            r = middle - 1;
    }

    return -1; // elemento nao encontrado
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);


  
   return 0;
}