#include <iostream>

using namespace std;

int main() {

	int a = 23;
	int b = 12;

	cout << a << " " << b << endl;

	a = b - a;
	b -= a;
	a += b;

	cout << a << " " << b << endl;

	a = b - a;
	b -= a;
	a += b;

	cout << a << " " << b << endl;

	return 0;	

}
