#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

template <class V>
V f(V t, V y) { return y - pow(t,2) + 1;}
template <class V>
V y(V t) { return pow(t,2) + 2 * t - 0.5*exp(t) + 1;}

void adams_predictor_corrector(double a, double b, int N, double alpha)
{
    double *t = new double[N], *w = new double[N]; 
    double h = (b - a)/N;
    t[0] = a;
    w[0] = alpha;

    cout.setf(ios::fixed);
    cout.precision(7);

    cout << "-------------------------------------------------------------------" << endl;
    cout << "t" << setw(25) << "y(t)" << setw(20) << "w" << setw(20) << "Error" << endl;
    cout << "-------------------------------------------------------------------" << endl;
    cout << t[0] << setw(20) << y(t[0]) << setw(20) << w[0] << setw(20) << abs(y(t[0]) - w[0]) << endl; 

    for (int i = 1; i <= 3; i++)
    {
        double k1 = h*f(t[i-1], w[i-1]);
        double k2 = h*f(t[i-1] + (h/2.0), w[i-1] + (k1/2));
        double k3 = h*f(t[i-1] + (h/2.0), w[i-1] + (k2/2));
        double k4 = h*f(t[i-1] + h, w[i-1] + k3);

        w[i] = w[i-1] + (k1 + 2*k2 + 2*k3 + k4) / 6;
        t[i] = a + i*h;

        cout << t[i] << setw(20) << y(t[i]) << setw(20) << w[i] << setw(20) << abs(y(t[i]) - w[i]) << endl; 
    }

    for (int i = 4; i <= N; i++)
    {
        double t_new = a + i*h;
        double w_new = w[3] + h*(55*f(t[3], w[3]) - 59*f(t[2], w[2]) + 37*f(t[1], w[1]) - 9*f(t[0],w[0])) / 24; 
        w_new = w[3] + h*(9*f(t_new, w_new) + 19*f(t[3], w[3]) - 5*f(t[2], w[2]) +f(t[1], w[1])) / 24;

        cout << t_new << setw(20) << y(t_new) << setw(20) << w_new << setw(20) << abs(y(t_new) - w_new) << endl;

        for (int j = 0; j <= 2; j++)
        {
            t[j] = t[j+1];
            w[j] = w[j+1];
        }

        t[3] = t_new; 
        w[3] = w_new; 
    }

    delete[] t; 
    delete[] w; 

}

int main()
{
    double a, b, alpha; //a = 0; b = 2; alpha = 0.5; int N = 10; double h = 0.1;
    int N;

    cout << "For the following separate your values with space key!" << endl;
    cout << "Enter the value for a, b, alpha, and N: "; 
    cin >> a >>  b >>  alpha >>  N;
    cout << endl;

    adams_predictor_corrector(a, b, N, alpha);

    return 0;

}

