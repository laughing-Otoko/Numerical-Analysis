#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

template <class f> //template for the functions
f p(f x) { return (-2/x); }
template <class f> 
f q(f x) { return (2/pow(x,2)); }
template <class f> 
f r(f x) { return (sin(log(x))/pow(x, 2)); }
template <class f> 
f y(f x) { return (1.1392070132*x + (-0.03920701320/pow(x,2)) - (3.0/10.0)*sin(log(x)) - (1.0/10.0)*cos(log(x))); } //exact solution

void linearFiniteDifference(double x1, double x2, double alpha, double beta, int N)
{
    double h = 0.1;
    double x = x1 + h;
    vector<double> a(N+2), b(N+2), c(N+2), d(N+2), l(N+2), u(N+2),z(N+2), w(N+2);
    a[0] = 0.0;
    b[0] = 0.0;
    c[0] = 0.0;
    d[0] = 0.0;
    l[0] = 0.0;
    u[0] = 0.0;
    z[0] = 0.0;
    
    a[1] = 2 + pow(h, 2)*q(x);
    b[1] = -1 + (h/2)*p(x);
    d[1] = -1*pow(h,2)*r(x) + (1 + (h/2)*p(x))*alpha;
    c[1] = 0.0;

    cout << "-----------------------------------------------------------------------------" << endl;
    cout << "xi" << setw(20) << "w[i]" << setw(15) << "y(xi)" << setw(20) << "|wi - y(xi)|" << endl;
    cout << "-----------------------------------------------------------------------------" << endl;

    for (int i = 2; i <= N-1; i++){
        x = x1 + i*h;
        a[i] = 2 + pow(h,2)*q(x);
        b[i] = -1 + (h/2)*p(x);
        c[i] = -1 - (h/2)*p(x);
        d[i] = -1*pow(h,2)*r(x);
    }

    x = x2 - h;
    a[N] =  2 + pow(h,2)*q(x);
    c[N] = -1 -(h/2)*p(x);
    d[N] = -1*pow(h,2)*r(x) + (1 - (h/2)*p(x))*beta;

    l[1] = a[1];
    u[1] = b[1] / a[1];
    z[1] = d[1] / l[1];

    for (int i = 2; i <= N; i++){
        l[i] = a[i] - c[i]*u[i-1];
        u[i] = b[i]/l[i];
        z[i] = (d[i] - c[i]*z[i-1]) / l[i];
    }

    w[0] = alpha;
    w[N+1] = beta;
    w[N] = z[N];

    for (int i = N-1; i > 0; i--){
        w[i] = z[i] - u[i]*w[i+1];
    }

    for (int i = 0; i <= N; i++){
        x = x1 + i*h;
        cout.setf(ios::fixed);
        cout.precision(8);
        cout << x << setw(15) << w[i] << setw(15) << y(x) << setw(15) << abs(w[i] - y(x)) << endl;
    }    
}

int main()
{
    double a(1), b(2), alpha(1), beta(2);
    int N = 10;

    linearFiniteDifference(a, b, alpha, beta, N);

    return 0;
}

