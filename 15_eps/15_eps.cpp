#include <iostream>
#include <iomanip>

using namespace std;

template<typename T>
T machine_epsilon() {
	T eTemp;
	T e = 1.0;
	do {
		e /= 2.0;
		eTemp = e + 1.0;
	} while (eTemp > 1.0);
	return e;
}

template<typename T>
T machine_zero() {
	T eTemp = 1.0;
	T e = 0.0;
	T eTempLast;
	do {
		eTempLast = eTemp;
		eTemp /= 2.0;
	} while (eTemp > e);
	return eTempLast;
}

template<typename T>
T machine_max_pos() {
	T eMax = pow(10, 10000);
	T e = 1.0;
	int exp = -1;
	do {
		e *= 2.0;
		exp++;
	} while (e < eMax);
	return pow(2, exp);
}

template<typename T>
T machine_max_neg() {
	T eMax = -pow(10, 10000);
	T e = -1.0;
	int exp = -1;
	do {
		e *= 2.0;
		exp++;
	} while (e > eMax);
	return -pow(2, exp);
}

int main() {
	cout << "float epsilon: " << machine_epsilon<float>() << endl;
	cout << "float machine zero: " << machine_zero<float>() << endl;
	cout << "sum of float epsilon and float zero: " << machine_epsilon<float>() + machine_zero<float>() << endl;
	cout << "difference of float epsilon and float zero: " << machine_epsilon<float>() - machine_zero<float>() << endl;
	cout << "float machine max positive: " << machine_max_pos<float>() << endl;
	cout << "float machine max negative: " << machine_max_neg<float>() << endl << endl;

	cout << "double epsilon: " << machine_epsilon<double>() << endl;
	cout << "double machine zero: " << machine_zero<double>() << endl;
	cout << "sum of double epsilon and double zero: " << machine_epsilon<double>() + machine_zero<double>() << endl;
	cout << "difference of double epsilon and double zero: " << machine_epsilon<double>() - machine_zero<double>() << endl;
	cout << "double machine max positive: " << machine_max_pos<double>() << endl;
	cout << "double machine max negative: " << machine_max_neg<double>() << endl << endl;

	cout << "long double epsilon: " << machine_epsilon<long double>() << endl;
	cout << "long double machine zero: " << machine_zero<long double>() << endl;
	cout << "sum of long double epsilon and long double zero: " << machine_epsilon<long double>() + machine_zero<long double>() << endl;
	cout << "difference of long double epsilon and long double zero: " << machine_epsilon<long double>() - machine_zero<long double>() << endl;
	cout << "long double machine max positive: " << machine_max_pos<long double>() << endl;
	cout << "long double machine max negative: " << machine_max_neg<long double>() << endl << endl;

	return 0;
}