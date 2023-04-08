#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

double f(double &t, double &y){ return 1 + (y/t);}

double fPrime(double &t, double &y){ return (-1*y)/(t*t);}

double T2(double &t, double &y, double &h){ return (f(t,y) + (h/2)*(fPrime(t, y)));}

double y(double &t){ return (t*log(t)) + 2*t;}

void taylors_method_Ord2(double a, double alpha, double h, int N)
{
    double t = a;
    double w = alpha;

    ofstream outstream;
    
    outstream.open("taylors_method_ord2.txt");
    if (outstream.fail())
    {
        cout << "Error: Could not open file!";
        exit(1);
    }

    outstream.setf(ios::fixed);
    outstream.precision(8);
    cout << "Printing into file!" << endl;
    outstream << "-------------------------------------------------------" << endl;
    outstream << "ti                 \t\twi                  \ty(ti)" << endl;
    outstream << "-------------------------------------------------------" << endl;
    outstream << t << "              " << w << "               " << y(t) << endl;


    int i = 1;
    while (i < N + 1)
    {
        w = w + h*T2(t,w,h);
        t = a + i*h;

        outstream << t << "              " << w << "               " << y(t) << endl;
        i++; 
    }

    cout << "Printing into file: Complete!" << endl;
    outstream.close();

}

int main()
{
    int N;
    double a, alpha, h; 

    cout << "\nFor the following separate values by space." << endl;
    cout << "Enter the values of(a,alpha,h,N): "; 
    cin >> a >> alpha >> h >> N; // 1, 2, 0.25, 4

    taylors_method_Ord2(a, alpha, h, N);

    return 0;


}