#include <iostream>
#include <cmath>

using namespace std;

double f(double t, double y) { return (y - pow(t,2) + 1);}

double y(double t) { return pow(t,2) + 2 * t - 0.5*exp(t) + 1;}

void modified_euler(double a, double alpha, double h, int N)
{
    double t = a;
    double w = alpha;

    cout << "--------------------------------------------------------------" << endl;
    cout << "t           \ty(t)           ModifiedEuler            error" << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout.setf(ios::fixed);
    cout.precision(7);
    cout << t << "        " << y(t) << "        " << w << "        " << y(t) - w << endl;

    int i = 1;
    while (i < N + 1)
    {
        w = w + (h/2)*(f(t,w) + f((t+h), w + h*f(t, w)));
        t = a + i * h;
        
        cout << t << "        " << y(t) << "        " << w << "        " << y(t) - w << endl;
        i++;
    }

}

int main()
{
    int N; //10
    double a, alpha, h; // 0, 0.5, 0.2
    
    cout << "\nFor the following separate values by space." << endl;
    cout << "Enter the values of(a,alpha,h,N): ";
    cin >> a >> alpha >> h >> N;

    modified_euler(a, alpha, h, N);
    
    return 0;


}