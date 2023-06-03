#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double t, double y){ return (y/t)- pow((y/t), 2);}
double y(double t){ return t/(1+log(t));}

void eulers_method(double a, double alpha, double h, int N)
{
    double t = a;
    double w = alpha;

    cout.setf(ios::fixed);
    cout.precision(7);

    cout << "----------------------------------------------------------------------------------------------------------" << endl;
    cout << "t" << setw(30) << "w" << setw(30) << "\ty(t)" << setw(30) <<  "[y-w]" << endl;
    cout << "----------------------------------------------------------------------------------------------------------" << endl;

    int   i = 1;
    while (i < N + 1)
    {
        w = w + h * f(t, w);
        t = a + i * h;

        cout << t << setw(30) << w << setw(30) << y(t) << setw(30) << y(t) - w << endl;
        i++;
    }

    cout << "\nProcedure complete!" << endl;
}

int main()
{
    
    double a, alpha, h;//double a = 1; double alpha = 1; int N = 10; double h = 0.1;
    int N;

    cout << "For the following separate your values with space key!" << endl;
    cout << "Enter the value for a, alpha, h and N: ";
    cin >> a >>  alpha >>  h >>  N;
    cout << endl;

    eulers_method(a, alpha, h, N);
  
    return 0;
}

