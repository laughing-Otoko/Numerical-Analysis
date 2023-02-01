#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

double f(double &t, double &y)
{
    return y - pow(t, 2) + 1 ;
}

double fPrime(double &t, double &y)
{
    return y - pow(t, 2) + 1 - (2*t);
}

double T4(double &t, double &y, double &h)
{
    return (((1 + (h/2) + (pow(h,2)/6) + (pow(h,3)/24))*(y - pow(t,2))) -(1 + (h/3) + (pow(h,2)/12)*(h*t))+ 1 + (h/2) + (pow(h,2)/6) + (pow(h,3)/24));
}

double y(double &t)
{
    return pow((t+1),2) - 0.5*exp(t);
}

int main()
{
    int N = 10;
    double h = 0.2;
    double a = 0;
    double w = 0.5;
    double t = 0;
    double error;
    ofstream outstream;

    outstream.open("taylorOrd4.dat");
    if (outstream.fail())
    {
        cout << "Error: Could not open file !";
        exit(1);
    }

    cout << "Printing into file!" << endl;
    outstream << "---------------------------------------------" << endl;
    outstream << "ti                wi              Error" << endl;
    outstream << "---------------------------------------------" << endl;
    outstream << t << "                " << w << "          " << abs(y(t) - w) << endl;
     
    int i = 1;

    while (i < N + 1)
    {
        
        w = w + h*T4(t, w, h);
        t = a + i*h;

        outstream.setf(ios::fixed);
        outstream.precision(6);
        outstream << t << "       " << w << "       " << abs(y(t) - w) << endl;
        i++;
    }

    cout << "Printing into file: complete!" << endl;
    outstream.close();

    return 0;
}