#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;


double f(double t, double y)
{
    return y - pow(t, 2) + 1;
}
double y(double t)
{
    return pow((t + 1), 2) - 0.5 * exp(t);
}

int main()
{
    int N = 10;
    double h = 0.2;
    double t = 0;
    double w = 0.5;
    int a = 0;
    ofstream outstream;

    outstream.open("euler.dat");


    cout << "Printing into text file" << endl;
    outstream << "---------------------------------------------" << endl;
    outstream << "t \t w \t y=y(t) \t [y-w]" << endl;
    outstream << "---------------------------------------------" << endl;
    outstream << t << " \t " << w << " \t " << y(t) << " \t " << y(t) - w << endl;

    int   i = 1;
    while (i < N + 1)
    {
        w = w + h * f(t, w);
        t = a + i * h;

        outstream.setf(ios::fixed);
        outstream.precision(7);
        outstream << t << " \t " << w << " \t " << y(t) << " \t " << y(t) - w << endl;
        i++;
    }

    cout << "Printing into file completed!";

    outstream.close();

    return 0;
}

