#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    
    vector<long long> arr(n + 1);
    arr[0] = 0;
    long long sum = 0, temp;

    for (int i = 1; i <= n; i++) {
        cin >> temp;
        sum += temp;
        arr[i] = sum;
    }

    int a, b;
    while (q--) {
        cin >> a >> b;
        cout << arr[b] - arr[a - 1] << '\n';
    }

    return 0;
}