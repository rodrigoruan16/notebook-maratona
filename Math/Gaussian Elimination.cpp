// Given a linear system, find the value of the variables

#include <bits/stdc++.h>

using namespace std;

// matrix: coefficient matrix (n*n)
// sums: vector of the resulting sum of each line (n)
vector<long double> gauss(vector<vector<long double>>& matrix, vector<long double>& sums) {
    int n = matrix.size();
    for(int i = 0; i < n; i++) {
        int max_row = i;
        long double max_val = std::abs(matrix[i][i]);
        
        for(int k = i + 1; k < n; k++) {
            if(std::abs(matrix[k][i]) <= max_val)
                continue;
            max_val = std::abs(matrix[k][i]);
            max_row = k;
        }

        if(max_row != i) {
            swap(matrix[i], matrix[max_row]);
            swap(sums[i], sums[max_row]);
        }

        for(int k = i + 1; k < n; k++) {
            long double factor = matrix[k][i] / matrix[i][i];
            matrix[k][i] = 0.0;

            for(int j = i + 1; j < n; j++)
                matrix[k][j] -= factor * matrix[i][j];
            sums[k] -= factor * sums[i];
        }
    }

    vector<long double> result(n);
    for(int i = n - 1; i >= 0; i--) {
        result[i] = sums[i];
        
        for(int j = i + 1; j < n; j++)
            result[i] -= matrix[i][j] * result[j];
        
        result[i] /= matrix[i][i];
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // Matrix size (n*n) and number of variables
    int n;
    cin >> n;

    // Read the coefficients (n for n lines)
    vector<vector<long double>> matrix(n, vector<long double>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cin >> matrix[i][j];
    }
    
    // Read the result of each line
    vector<long double> sum(n);
    for(int i = 0; i < n; i++)
        cin >> sum[i];

    // Vector with the value of each variable
    auto answer = gauss(matrix, sum);

    cout << fixed << showpoint;
    cout << setprecision(2);
    cout << answer[0];
    for(int i = 1; i < n; i++)
        cout << " " << answer[i];
    cout << '\n';
    return 0;
}
