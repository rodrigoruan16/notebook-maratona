#include <bits/stdc++.h>

using namespace std;

vector<bool> primes;

void sieve(long long n) {
    primes = vector<bool>(n + 1, true);
    primes[0] = primes[1] = false;

    for (int i = 2; i <= sqrt(n); i++) {
        if (primes[i]) {
            for (int j = i * i; j <= n; j += i) {
                primes[j] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    sieve(100); 
    
    return 0;
}