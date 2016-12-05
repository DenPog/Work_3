// Work_3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>      // std::setw    
#include <new>

int q = 0, N = 0;
void show_a();

int **a;

using namespace std;

int main() {

	setlocale(0, "");
	do {
		cout << "vvedite chislo <10" << endl;
		cin >> N;
	} while (N > 10);

	// ñîçäàíèå ìàññèâà
	a = new int *[N];    // ìàññèâ óêàçàòåëåé 
	for (int i = 0; i < N; i++) {
		a[i] = new int[N];     // èíèöèàëèçàöèÿ óêàçàòåëåé
	}

	int n = N;
	// ðàáîòà
	for (int i = 0; i < n;) {
		for (int j = i; j < n; ++j) {
			q++;
			a[i][j] = q;

		}
		for (int j = i + 1; j < n; ++j) {
			q++;
			a[j][n - 1] = q;

		}
		--n;
		for (int j = n - 1; j >= i; --j) {
			q++;
			a[n][j] = q;

		}
		++i;
		for (int j = n - 1; j >= i; --j) {
			q++;
			a[j][i - 1] = q;

		}
	}

	show_a();
	system("pause");
	return 0;
}

void show_a() {
	for (int i = 0; i < N; i++) {
		cout << endl;
		for (int j = 0; j < N; j++) {
			cout << setw(4) << a[i][j];
		}
		cout << endl;
	}
}
