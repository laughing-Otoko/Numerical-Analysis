#include <iostream>
#include <vector>
#include <cmath>
#include <functional>
#include <stdexcept>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;
vector<double> pade_approximation(const vector<double>& a, int m, int n) {
    int N = m + n;

    // Step 3: Initialize q and p
    vector<double> q(m + 1, 0.0);
    vector<double> p(n + 1, 0.0);
    q[0] = 1;
    p[0] = a[0];

    // Steps 4-10: Set up the linear system with matrix B
    MatrixXd B(N, N + 1);
    B.setZero();

    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (j < i) {
                if (j < n) {
                    B(i, j) = 0;
                }
            } else if (j == i) {
                if (j < n) {
                    B(i, j) = 1;
                }
            } else {
                if (j - n < m) {
                    B(i, j) = -a[i - j + n];
                }
            }
        }
        B(i, N) = a[i];
    }

    // Steps 11-22: Solve the linear system using QR decomposition
    HouseholderQR<MatrixXd> qr(B.leftCols(N));
    VectorXd x = qr.solve(B.col(N));



    // Steps 20-22: Perform backward substitution
    for (int i = n; i <= N - 1; ++i) {
        q[i - n + 1] = x[i];
    }

    for (int i = 1; i <= n; ++i) {
        double sum = 0;
        for (int j = n + 1; j < N; ++j) {
            sum += B(i, j) * q[j - n];
        }
        p[i] = B(i, N) - sum;
    }

    // Combine q and p into a single output vector
    vector<double> result(q.size() + p.size());
    for (int i = 0; i < q.size(); ++i) {
        result[i] = q[i];
    }
    for (int i = 0; i < p.size(); ++i) {
        result[q.size() + i] = p[i];
    }

    return result;
}

int main() {
    // Function to approximate: f(x) = x^2 + x^3
    // Maclaurin series coefficients for f(x)
    vector<double> a = {0, 0, 1, 1, 0, 0, 0};

    int m = 2; // Degree of P(x)
    int n = 1; // Degree of Q(x)

    vector<double> coeffs = pade_approximation(a, m, n);

    for (int i = 0; i < coeffs.size(); ++i) {
        cout << "Coefficient " << i << ": " << coeffs[i] << endl;
    }

    return 0;
}

