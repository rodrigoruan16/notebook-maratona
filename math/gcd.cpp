#include <bits/stdc++.h>

using namespace std;

int GCD(int a, int b) {
    if (a == 0)
        return b;

    return GCD(b%a, a);
}