#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double t, double y) { return (y - pow(t,2) + 1);}

double y(double t) {return pow(t,2) + 2*t - 0.5*exp(t) +1;}

void heuns_method(double a, double alpha, double h, double N)
{
    double t = a;
    double w = alpha;
    double error;

    cout.setf(ios::fixed);
    cout.precision(7);
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << "t              \t\ty(t)                \tHeun                \terror" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;    
    cout << t << setw(24) << y(t) << setw(24) << w << setw(24) << abs(y(t) - w) << endl;

    int i = 1;
    while (i < N + 1)
    {
        w = w + (h/4)*(f(t, w) + 3*f(t + (2*h/3), w + (2*h/3)*f(t + (h/3), w + (h/3)*f(t,w))));
        t = a + i * h;
        error = y(t) - w;

        cout << t << "            \t" << y(t) << "           \t"  << w << "           \t" << error << endl;
        i++;
    }
}

int main() 
{
    int N;
    double a, alpha, h; // 0, 0.5, 0.2, 10
    

    cout << "\nFor the following separate values by space." << endl;
    cout << "Enter the values of(a,alpha,h,N): ";
    cin >> a >> alpha >> h >> N;
    heuns_method(a, alpha, h, N);

    return 0;
}