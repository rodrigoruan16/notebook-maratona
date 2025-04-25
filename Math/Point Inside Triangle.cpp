// Check if point lies inside a triangle using barycentric coordinates 
#include <bits/stdc++.h>
using namespace std;

struct point {
    double x, y;
};

bool is_point_inside_triangle(point A, point B, point C, point P) {
    // Calculate the barycentric coordinates
    // of point P with respect to triangle ABC
    double denominator = ((B.y - C.y) * (A.x - C.x) + (C.x - B.x) * (A.y - C.y));
    double a = ((B.y - C.y) * (P.x - C.x) + (C.x - B.x) * (P.y - C.y)) / denominator;
    double b = ((C.y - A.y) * (P.x - C.x) + (A.x - C.x) * (P.y - C.y)) / denominator;
    double c = 1 - a - b;
 
    // Check if all barycentric coordinates
    // are non-negative
    return a >= 0 && b >= 0 && c >= 0; // returns true if point lies exactly in the border
    // return a > 0 && b > 0 && c  0; returns false if point lies exactly in the border
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    point A, B, C, P;
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
    cin >> P.x >> P.y;
    
    cout << (is_point_inside_triangle(A, B, C, P) ? "YES\n" : "NO\n");
    return 0;
}