#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}
void stat(const double A[],int N,double B[]){
	double ArithmeticMean, StandardDeviation, GeometricMean, HarmonicMean, Max = A[0], Min = A[0];
	double sum = 0, GM = 1, sum2 = 0, sumh = 0; 
	for(int i = 0; i < N; i++){
		sum += A[i];
		sum2 += pow(A[i],2);
		GM *= A[i];
		sumh += 1.0/A[i];	
	}
	ArithmeticMean = sum/N;
	B[0] = ArithmeticMean;
	StandardDeviation = sqrt((sum2/N)-pow((sum/N),2));
	B[1] = StandardDeviation;
	GeometricMean = pow(GM,(1.0/N));
	B[2] = GeometricMean;
	HarmonicMean = N/sumh;
	B[3] = HarmonicMean;
	for(int i = 1; i < N ; i++){
		if(A[i] > Max) Max = A[i];
		if(A[i] < Min) Min = A[i];
	}
	B[4] = Max;
	B[5] = Min;
}