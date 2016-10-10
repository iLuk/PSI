#include <iostream>
#include <cmath>

using namespace std;

int main() {

	// AND 0.6, th = 1; 
	// OR 1.1, th = 1; 
	// NOT w3 = -1, th = -0.5

	double
		w_and = 0.6,
		w_or = 1.1,
		w_not = -1,
		th_and = 1,
		th_or = 1,
		th_not = -0.5,
		a,
		b,
		o;

	// AND
	cout << "Insert (AND): ";
	cin >> a >> b;

	o = a*w_and + b*w_and;

	if (o >= th_and)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	// OR
	cout << "Insert (OR): ";
	cin >> a >> b;

	o = a*w_or + b*w_or;

	if (o >= th_or)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	// NOT
	cout << "Insert (NOT): ";
	cin >> a;

	o = a*w_not;

	if (o >= th_not)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	system("pause");

}