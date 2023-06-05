#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

//Finding the index of the max abs val in a vector
int maxAbsIndex(vector<double> &v)
{
    return max_element(v.begin(), v.end(), [](const double& a, const double& b){
        return abs(a) < abs(b);
    }) - v.begin();
}

//Multiplying a matrix with a vector
vector<double> matrixMultiply(vector<vector<double>>& mat, vector<double>& vec)
{
   vector<double> result(vec.size(), 0.0) ;
   
   for (int i = 0; i < mat.size(); i++){
    for (int j = 0; j < vec.size(); j++){
        result[i] += mat[i][j] * vec[j];
    }
   }

   return result;
}

double infiniteNorm(vector<double>& vec)
{
    return *max_element(vec.begin(), vec.end(), [](const double& a, const double& b){
        return abs(a) < abs(b);
    });
}

//The power method with the Aitken's delta-squared procedure
void powerMethod(vector<vector<double>>& A, vector<double>& x, double TOL, int N)
{
    int k = 1;
    double mu0 = 0, mu1 = 1, mu;
    int p = maxAbsIndex(x);

    for (double &xi : x) xi /= x[p];

    while (k <= N){
         vector<double> y = matrixMultiply(A, x);
         mu = y[p];
         mu = mu0 - pow(mu1-mu0, 2) / (mu - 2*mu1 + mu0); //Aitken's delta-squared procedure
         p = maxAbsIndex(y);

         if (y[p] == 0) {
            cout << "Eigenvector: ";
            for (double xi : x) cout << xi << " ";
            cout << "\nA has the eigenvalue 0, select a new vector x and restart\n";
            return;
         }
         double ERR = infiniteNorm(x);
         for (double& yi : y) yi /= y[p];
         ERR -= infiniteNorm(y);
         ERR = abs(ERR);
         x = y;
         if (ERR < TOL && k >= 4){
            cout << "Eigenvalue: " << mu << "\nEigenvector: ";
            for (double xi : x) cout << xi << " "; 
            cout << endl;
            return;
         }
         k++;
         mu0 = mu1;
         mu1 = mu;
    }
    cout << "The maximum number of iterations exceed" << endl;
}

int main()
{
    int n = 3 ;
    double TOL = 1e-2;
    int N = 4;

    cout << "The dimensions (n): " << n << endl;
    

    vector<vector<double>> A(n, vector<double>(n));

    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> A[i][j];
        }
    }
    vector<double> x(n);
    for (int i = 0; i < n; i++){
        cin >> x[i];
    }
    
    cout << "The tolerance (TOL): " << TOL << endl;

    cout << "Enter the number of iterations (N): " <<  N << endl;

    powerMethod(A, x, TOL, N);

    return 0;
}