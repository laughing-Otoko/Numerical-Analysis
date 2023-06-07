#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

double f(double x, double y, double yp) {
    return yp; // Simple example: y'' = y', with solution y(x) = e^x
}

vector<double> eulers_method(double a, double b, double alpha, double initial_guess, double h) {
    double x = a;
    double y = alpha;
    double yp = initial_guess;

    while (x < b) {
        double k1_y = h * yp;
        double k1_yp = h * f(x, y, yp);

        double y_temp = y + k1_y;
        double yp_temp = yp + k1_yp;

        double k2_y = h * yp_temp;
        double k2_yp = h * f(x + h, y_temp, yp_temp);

        y += (k1_y + k2_y) / 2;
        yp += (k1_yp + k2_yp) / 2;

        x += h;
    }

    return {y, yp};
}

vector<double> shooting_method(double a, double b, double alpha, double beta, double initial_guess, double h, double tolerance, int max_iterations) {
    int iteration = 0;
    double lower_bound = initial_guess - 1;
    double upper_bound = initial_guess + 1;

    while (iteration < max_iterations) {
        double guess = (lower_bound + upper_bound) / 2;
        vector<double> Y_solution = eulers_method(a, b, alpha, guess, h);

        double error = Y_solution[0] - beta;

        if (abs(error) < tolerance) {
            return Y_solution;
        }

        if (error > 0) {
            upper_bound = guess;
        } else {
            lower_bound = guess;
        }

        iteration++;
    }

    throw runtime_error("Shooting method did not converge within the maximum number of iterations.");
}

int main() {
    double a = 0;
    double b = 1;
    double alpha = 1;
    double beta = exp(1);
    double initial_guess = 1;
    double h = 0.1;
    double tolerance = 1e-6;
    int max_iterations = 100;

    cout.setf(ios::fixed);
    cout.precision(7);

    try {
        vector<double> solution = shooting_method(a, b, alpha, beta, initial_guess, h, tolerance, max_iterations);
        cout << "Solution found: y(" << b << ") = " << solution[0] << ", y'(" << b << ") = " << solution[1] << endl;
    } catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
