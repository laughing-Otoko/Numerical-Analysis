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

void taylors_method_Ord4(double a, double alpha, double h, int N)
{
    double t = a;
    double w = alpha;

    ofstream outstream;

    outstream.open("taylorOrd4.txt");
    if (outstream.fail())
    {
        cout << "Error: Could not open file !";
        exit(1);
    }

    outstream.setf(ios::fixed);
    outstream.precision(6);
    cout << "Printing into file!" << endl;
    outstream << "-------------------------------------------------------" << endl;
    outstream << "ti                 \t\twi                  \ty(ti)" << endl;
    outstream << "-------------------------------------------------------" << endl;
    outstream << t << "              " << w << "               " << y(t) << endl;
    
    int i = 1;

    while (i < N + 1)
    {
        
        w = w + h*T4(t, w, h);
        t = a + i*h;

        outstream << t << "              " << w << "               "  << abs(y(t) - w) << endl;
        i++;
    }

    cout << "Printing into file: complete!" << endl;
    outstream.close();
}
int main()
{
    int N;
    double a, alpha, h; 

    cout << "\nFor the following separate values by space." << endl;
    cout << "Enter the values of(a,alpha,h,N): "; 
    cin >> a >> alpha >> h >> N; // 0, 0.5, 0.2, 10

    taylors_method_Ord4(a, alpha, h, N);

    return 0;
}