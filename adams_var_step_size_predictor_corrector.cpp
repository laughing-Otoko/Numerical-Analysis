#include <iostream>
#include <cmath>

using namespace std;

double f(double t, double y) {
    // Define the differential equation f(t, y)
    return (t * y - pow(t, 2) * pow(y, 2));
}

void RK4(double h, double v0, double x0, double &v1, double &x1, double &v2, double &x2, double &v3, double &x3) {
    double K1 = h * f(x0, v0);
    double K2 = h * f(x0 + h/2, v0 + K1/2);
    double K3 = h * f(x0 + h/2, v0 + K2/2);
    double K4 = h * f(x0 + h, v0 + K3);

    v1 = v0 + (K1 + 2*K2 + 2*K3 + K4) / 6;
    x1 = x0 + h;

    K1 = h * f(x1, v1);
    K2 = h * f(x1 + h/2, v1 + K1/2);
    K3 = h * f(x1 + h/2, v1 + K2/2);
    K4 = h * f(x1 + h, v1 + K3);

    v2 = v1 + (K1 + 2*K2 + 2*K3 + K4) / 6;
    x2 = x1 + h;

    K1 = h * f(x2, v2);
    K2 = h * f(x2 + h/2, v2 + K1/2);
    K3 = h * f(x2 + h/2, v2 + K2/2);
    K4 = h * f(x2 + h, v2 + K3);

    v3 = v2 + (K1 + 2*K2 + 2*K3 + K4) / 6;
    x3 = x2 + h;
}

void avspc(double a, double b, double alpha, double TOL, double hmax, double hmin) {
    double t0 = a;
    double w0 = alpha;
    double h = hmax;
    int FLAG = 1;
    int LAST = 0;
    int NFLAG;

    cout << "i" << "\t" << "ti" << "\t\t" << "wi" << "\t\t" << "h" << endl;
    cout << "------------------------------------------------" << endl;
    cout << "0" << "\t" << t0 << "\t\t" << w0 << "\t\t" << "-" << endl;

    double w1, w2, w3, t1, t2, t3;
    RK4(h, w0, t0, w1, t1, w2, t2, w3, t3);
    int i = 4;
    double t = t3 + h;

    while (FLAG == 1) {
        double WP = w3 + h/24 * (55*f(t3, w3) - 59*f(t2, w2) + 37*f(t1, w1) - 9*f(t0, w0));
        double WC = w3 + h/24 * (9*f(t, WP) + 19*f(t3, w3) - 5*f(t2, w2) + f(t1, w1));
        double sigma = 19 * abs(WC - WP) / (270 * h);

        if (sigma <= TOL) {
            w0 = WC;
            t0 = t;
            cout << i-3 << "\t" << t3 << "\t\t" << w3 << "\t\t" << h << endl;
            cout << i-2 << "\t" << t2 << "\t\t" << w2 << "\t\t" << h << endl;
            cout << i-1 << "\t" << t1 << "\t\t" << w1 << "\t\t" << h << endl;
            cout << i << "\t" << t0 << "\t\t" << w0 << "\t\t" << h << endl;

            if (LAST == 1) {
                FLAG = 0;
            } else {
                i += 1;
                NFLAG = 0;
            }
        } else {
            double q = pow(TOL / (2 * sigma), 0.25);
            if (q < 0.1) {
                h = 0.1 * h;
            } else {
                h = q * h;
            }
            if (h < hmin) {
                FLAG = 0;
                cout << "hmin exceeded" << endl;
            } else {
                if (NFLAG == 1) {
                    i = i - 3;
                }
                RK4(h, w2, t2, w3, t3, w1, t1, w0, t0);
                i += 3;
                NFLAG = 1;
            }
    }

    if (sigma <= 0.1 * TOL || t0 + h > b) {
        double q = pow(TOL / (2 * sigma), 0.25);
        if (q > 4) {
            h = 4 * h;
        } else {
            h = q * h;
        }
        if (h > hmax) {
            h = hmax;
        }
        if (t0 + 4*h > b) {
            h = (b - t0) / 4;
            LAST = 1;
        }
        RK4(h, w2, t2, w3, t3, w1, t1, w0, t0);
        i += 3;
        NFLAG = 1;
    }

    t = t0 + h;
    }
}

int main()
{
    double a = 0;
    double b = 1;
    double alpha = 0;
    double TOL = 1e-6;
    double hmax = 0.1;
    double hmin = 1e-5;
    avspc(a, b, alpha, TOL, hmax, hmin);

    return 0;
}