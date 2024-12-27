#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double A[],int N,double B[]){
    double sum = 0;
    double SD = 0;
    double GM = 1;
    double HM = 0;
    double Max = A[0];
    double Min = A[0];
    
    for(int i=0; i<N ;i++){
        sum += A[i];
        
    }
    double mean = sum/N;
    
    for(int i=0; i<N ;i++){
        SD += pow(A[i]-mean,2);
        GM *=A[i];
        HM += 1.0/A[i];
        if(A[i] >= Max) Max = A[i];
        if(A[i] <= Min) Min = A[i]; 
    }
    
    
    double StandardDeviation = pow((SD/N),0.5);
    double GeometricMean = pow(GM,1.0/N);
    double HarmonicMean = N/HM;
    
    B[0] = mean;
    B[1] = StandardDeviation;
    B[2] = GeometricMean;
    B[3] = HarmonicMean;
    B[4] = Max;
    B[5] = Min;
}