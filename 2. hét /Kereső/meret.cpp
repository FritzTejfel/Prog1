#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

void kiir(double tomb[], int db) {

	for(int i = 0; i < db ;i++) {

		std::cout << tomb[i] << std::endl;

	}
	
}

double tavolsag(double PR[], double PRv[], double n) {

	double osszeg = 0;
	
	for(int i = 0; i < n;++i) {
		
		osszeg += (PRv[i] - PR[i]) * (PRv[i] - PR[i]);
		
	}

	return sqrt(osszeg);
}


int main (void) {

		double L[4][4] = {
			{0.0, 0.0, 1.0 / 3.0, 0.0},
			{1.0, 1.0/2.0, 1.0/ 3.0, 1.0},
			{0.0, 1.0 / 2.0, 0.0, 0.0},
			{0.0, 0.0, 1.0/ 3.0, 0.0}
		};

		double PR[4] = {0.0, 0.0, 0.0, 0.0};
		double Prv[4] = {1.0 / 4.0, 1.0 / 4.0, 1.0 / 4.0, 1.0 / 4.0};

		for(;;) {

			for(int i = 0; i < 4; ++i) {
				PR[i] = 0.0;
				for(int j= 0; j < 4; j++) {

					PR[i] += (L[i][j] * Prv[j]);

				}
			}


			if(tavolsag(PR, Prv, 4) < 0.00001) {
				break;
			}

			for(int i=0; i< 4; i++) {

				Prv[i] = PR[i];

			}

		}

		kiir(PR, 4);

		return 0;
}



