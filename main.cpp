#include <iostream>
#include <sstream>
#include <conio.h>
#include <bits/stdc++.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;
struct Matrix {
	double a[2][2] = {{0,0}, {0,0}};
	Matrix operator* (const Matrix &ctx) {
		Matrix product;
		for (int i = 0; i < (2); i++) for (int j = 0; j < (2); j++) for (int k = 0; k < (2); k++) {
			product.a[i][k] += a[i][j] * ctx.a[j][k];
		}
		return product;
	}
};

Matrix exp_pow(Matrix a, int k) {
	Matrix total;
	for (int i = 0; i < (2); i++) {
    	total.a[i][i] = 1;
	}
	while (k > 0) {
		if (k % 2) {
			total = total * a;
		}
		a = a*a;
		k /= 2;
	}
	return total;
}

string extractInt(string str)
{
	size_t i = 0;
	for ( ; i < str.length(); i++ ){ if ( isdigit(str[i]) ) break; }

		str = str.substr(i, str.length() - i );

	int id = atoi(str.c_str());

	return to_string(id);
}

int main(int argc, char** argv) {
	int n; double p; string argument;
	cin >> n >> p;
	
	Matrix matrix;
	matrix.a[0][0] = 1 - p;
	matrix.a[0][1] = p;
	matrix.a[1][0] = p;
	matrix.a[1][1] = 1 - p;
	
    Matrix total = exp_pow(matrix, n);
    
    if (argv[1]) {
    	argument = argv[1];
    	if (argument.find("--setprecision=") != string::npos) {
    		argument = extractInt(argument);
		}
		cout << setprecision(stoi(argument)) << fixed << total.a[0][0] << endl;
	}
	else {
		cout << total.a[0][0] << endl;
	}
	getch(); // Pause
	return 0;
}
