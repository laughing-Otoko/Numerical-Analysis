//Runge-Kutta-Fehlberg for IVP
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

template <class V>
V f(V t, V y) { return y - pow(t,2) + 1;}
template <class V>
V y(V t) { return pow(t,2) + 2 * t - 0.5*exp(t) + 1;}

void rkf45(double a, double b, double alpha, double TOL, double hmin, double hmax) //rkf45 (Runge-kutta-fehlberg of order 4 and order 5)
{
    double t = a;
    double w = alpha;
    double h = hmax;
    bool FLAG = 1;
    
    ofstream oustream;

    oustream.open("rkf45.dat");
    if (oustream.fail()){
        cout << "Error!";
        exit(1);
    }

    oustream.setf(ios::fixed);
    oustream.precision(7);
    oustream << "---------------------------------------------------------------------------------------------------------------" << endl;
    oustream << "t          \t\ty(t)           \tw4       \t\th       \t\tR       |y(t) - w4|         rfk5         |y(t) - w5| " << endl;
    oustream << "---------------------------------------------------------------------------------------------------------------" << endl;
    oustream << t << setw(15) << y(t) << setw(60)  << w << endl;

    while (FLAG) 
    {
        double k1 = h * f(t, w);
        double k2 = h * f(t + (1.0/4.0)*h, w + (1.0/4.0)*k1);
        double k3 = h * f(t + (3.0/8.0)*h, w + (3.0/32.0)*k1 + (9.0/32.0)*k2);
        double k4 = h * f(t + (12.0/13.0)*h, w + (1932.0/2197.0)*k1 - (7200.0/2197.0)*k2 + (7296.0/2197.0)*k3);
        double k5 = h * f(t +h, w + (439.0/216.0)*k1 - 8.0*k2 + (3680.0/513.0)*k3 - (845.0/4104.0)*k4);
        double k6 = h * f(t + (1.0/2.0)*h, w - (8.0/27.0)*k1 + 2.0*k2 - (3544.0/2565.0)*k3 + (1859.0/4104)*k4 - (11.0/40.0)*k5);

        double R = (1.0/h) * abs((1.0/360.0)*k1 - (128.0/4275.0)*k3 - (2197.0/75240.0)*k4 + (1.0/50.0)*k5 + (2.0/55.0)*k6);

        if (R <= TOL){
            t = t + h; 
           double w4 = w + (25.0/216.0)*k1 + (1408.0/2565.0)*k3 + (2197.0/4104.0)*k4 - (1.0/5.0)*k5;
           double w5 = w + (16.0/135.0)*k1 + (6656.0/12825.0)*k3 + (28561.0/56430.0)*k4 - (9.0/50.0)*k5 + (2.0/55.0)*k6;
           oustream << t << setw(15) << y(t) << setw(15) << w4 << setw(15) << h << setw(15) << R << setw(15)  << abs(y(t) - w4) << setw(15) << w5 << setw(15) << y(t) - w5 << endl; 
        }
        double delta = 0.84*pow((TOL / R), (1.0/4.0));

        if (delta <= 0.1){
            h = 0.1*h;
        }
        else if (delta >= 4){
            h = 4.0*h;
        }
        else{
            h = delta*h;
        }

        if (h > hmax){
            h = hmax;
        }
        if (t >= b){
            FLAG = false;
        }
        else if ((t+h) > b){
            h = b - t;
        }
        else if (h < hmin){
            FLAG = false;
            oustream << "MININUM H EXCEED\n";
            oustream << "PROCEDURE COMPLETED UNSUCCESSFULLY" << endl;
        }
    }
    cout << "Writing is complete!" << endl;
}

int main()
{
    double a = 0, b = 2;
    double hmin = 0.01, hmax = 0.25;
    double TOL = pow(10, -5);
    double alpha = 0.5;

    rkf45(a,b,alpha,TOL,hmin,hmax);

    return 0;
}
