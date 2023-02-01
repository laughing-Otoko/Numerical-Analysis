#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

double f(double &t, double &y)
{
    return 1 + (y/t) ;
}

double fPrime(double &t, double &y)
{
    return (-1*y)/(t*t);
}

double T2(double &t, double &y, double &h)
{
    return (f(t, y) + (h/2)*(fPrime(t, y)));
}

double y(double &t)
{
    return (t*log(t)) + 2*t;
}

int main()
{
    int N = 4;
    double h = 0.25;
    double a = 1;
    double w = 2;
    double t = 1;

    ofstream outstream;

    outstream.open("taylor1c.dat");
    if (outstream.fail())
    {
        cout << "Error: Could not open file !";
        exit(1);
    }

    cout << "Printing into file!" << endl;
    outstream << "---------------------------------------------" << endl;
    outstream << "ti                wi              y(ti)" << endl;
    outstream << "---------------------------------------------" << endl;
    outstream << t << "                " << w << "          " << abs(y(t) - w) << endl;
     
    int i = 1;

    while (i < N + 1)
    {
        
        w = w + h*T2(t, w, h);
        t = a + i*h;

        outstream.setf(ios::fixed);
        outstream.precision(8);
        outstream << t << "       " << w << "       " << y(t)  << endl;
        i++;
    }

    cout << "Printing into file: complete!" << endl;
    outstream.close();

    return 0;
}