#include<stdio.h>
#include<cmath>
#include<iostream>
using namespace std;
int main()
{
	double n;
	double N;
	cin >> n;
	if (n >= 0)
		printf("%.2f\n",n );
	else
	{
		N = n*(-1);
		printf("%.2lf", N);
	}
	return 0;
}
