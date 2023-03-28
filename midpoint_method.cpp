#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double t, double y) { return (y - pow(t,2) + 1);}

double y(double t) {return pow(t,2) + 2*t - 0.5*exp(t) +1;}

void midpoint_method(double a, double alpha, double h, int N)
{
    double t = a;
    double w = alpha;

    cout.setf(ios::fixed);
    cout.precision(7);
    cout << "------------------------------------------------------------------------" << endl;
    cout << "t              \t\ty(t)              midpoint               error" << endl;
    cout << "------------------------------------------------------------------------" << endl;    
    cout << t << setw(20) << y(t) << setw(20) << w << setw(21) << abs(y(t) - w) << endl;

    int i = 1;
    while (i < N + 1)
    {
        w = w + h * f(t + (h/2), w + (h/2)*f(t,w));
        t = a + i * h;

        
        cout << t << "           " << y(t) << "           "  << w << "            " <<y(t) - w << endl;
        i++;
    }
}

int main()
{
    int N = 10;
    double a, alpha, h; // 0, 0.5, 0.2, 10


    cout << "\nFor the following separate values by space." << endl;
    cout << "Enter the values of(a,alpha,h,N): ";
    cin >> a >> alpha >> h >> N;

    midpoint_method(a, alpha, h, N);

    return 0;
}