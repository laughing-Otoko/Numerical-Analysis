#include <iostream>
#include <cmath>

using namespace std;

double f(double t, double y) { return (y - pow(t,2) + 1);}

double y(double t) {return pow(t,2) + 2*t - 0.5*exp(t) +1;}

void rkOrd4(double a, double alpha, double h, int N)
{
    double t = a;
    double w = alpha;
    double error;
    double k1, k2, k3, k4;

    cout << "----------------------------------------------------------------------------------" << endl;
    cout << "t             \t\ty(t)                \tRunge-Kutta(4)              error" << endl;
    cout << "----------------------------------------------------------------------------------" << endl;    
    cout.setf(ios::fixed);
    cout.precision(7);
    cout << t << "               " << y(t) << "               "  << w << "               " << abs(y(t) - w) << endl;

    int i = 1;  
    while (i < N + 1)
    {
        k1 = h*f(t,w);
        k2 = h*f(t + (h*0.5), w + (k1*0.5));
        k3 = h*f(t + (h*0.5), w + (k2*0.5));
        k4 = h*f(t + h, w + k3);

        w = w + ((k1 + 2*k2 + 2*k3 + k4)/6);
        t = a + i*h;
        error = y(t) - w;
        
        
        cout << t << "            \t" << y(t) << "           \t"  << w << "           \t" << error << endl;
        i++;
    }

}


int main()
{
    int N;
    double a, alpha, h; 

    cout << "\nFor the following separate values by space." << endl;
    cout << "Enter the values of(a,alpha,h,N): "; 
    cin >> a >> alpha >> h >> N; // 0, 0.5, 0.2, 10

    rkOrd4(a, alpha, h, N);
    return 0;
}