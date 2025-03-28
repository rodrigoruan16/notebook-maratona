#include <bits/stdc++.h>
 
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<long long> arr(n + 1);

    long long sum = 0, temp;

    for (int i = 1; i <= n; i++) {
        cin >> temp;
        sum = sum ^ temp;
        arr[i] = sum;
    }

    int a, b;
    while (q--) {
        cin >> a >> b;

        cout << (arr[b] ^ arr[a - 1]) << '\n';
    }

    return 0;
}