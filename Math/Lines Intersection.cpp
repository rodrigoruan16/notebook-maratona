// Encontra interseção de duas retas descritas por ax+by=c.
#include <bits/stdc++.h>
 using namespace std;
 
 int main() {
     double a1, b1, c1, a2, b2, c2;
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    double det = a1*b2 - a2*b1;
    if (fabs(det) < 1e-9) {
        cout << "Paralelas";
    } else {
        double x = (b2*c1 - b1*c2) / det;
        double y = (a1*c2 - a2*c1) / det;
        cout << x << " " << y;
    }
    return 0;
 }
