#include "FuzzyNumber_Private.h"
#include "FuzzyNumber_Public.h"

int main()
{
	FuzzyNumber_Private A1(4, 1, 7), B1;
	FuzzyNumber_Public A2(6, 3, 9), B2;

	cout << "A1 = " << A1 << endl;

	cin >> B1;
	cout << "B1 = " << B1 << endl;

	cout << "A2 = " << A2 << endl;

	cin >> B2;
	cout << "B2 = " << B2 << endl;

	cout << "Size of private class: " << sizeof(A1) << endl;
	cout << "Size of public class: " << sizeof(A2) << endl;

	FuzzyNumber_Private C1 = A1 + B1;
	cout << "C1 = " << C1 << endl;

	FuzzyNumber_Private D1 = A1 * B1;
	cout << "D1 = " << D1 << endl;

	FuzzyNumber_Public C2 = A2 * B2;
	cout << "C2 = " << C2 << endl;

	FuzzyNumber_Public D2 = A2 * B2;
	cout << "D2 = " << D2 << endl;

	cout << "++B1: " << ++B1 << endl;
	cout << "--B1: " << --B1 << endl;
	cout << "B1++: " << B1++ << endl;
	cout << "B1--: " << B1-- << endl << endl;

	cout << "++B2: " << ++B2 << endl;
	cout << "--B2: " << --B2 << endl;
	cout << "B2++: " << B2++ << endl;
	cout << "B2--: " << B2-- << endl << endl;
}
