#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

struct stru {

	double	x1,
		x2,
		x3,
		d;
};

int Funct(double x, double  y, double z, double  w1, double  w2, double w3);

int main() {

	double	w1 = -0.25,
			w2 = -0.25,
			w3 = 0.75,
			b = 0.25,
			b_l = 0,
			n = 0.001; // n=0.001

	int l_inter = 1000;

	double p1, p2, p3;

	stru Stru[8] = {
		(1,1,1,1),
		(1,1,-1,-1),
		(1,-1,1,1),
		(1,-1,-1,-1),
		(-1,1,1,1),
		(-1,1,-1,-1),
		(-1,-1,1,1),
		(-1,-1,-1,1)
	};

	// BEZ NAUCZYCIELA

	cout << "BEZ NAUCZYCIELA\n\n";
	cout << "START\nw1=" << w1 << "\nw2=" << w2 << "\nw3=" << w3 << endl;

	for (int i = 0; i < l_inter; i++) {

		for (int j = 0; j < 8; j++) {

			double y = Funct(Stru[j].x1, Stru[j].x2, Stru[j].x3, w1, w2, w3);

			w1 += n*y*Stru[j].x1;
			w2 += n*y*Stru[j].x2;
			w3 += n*y*Stru[j].x3;
		}

	}

	cout << "END\nw1=" << w1 << "\nw2=" << w2 << "\nw3=" << w3 << endl;

	while (true) {

		cout << "\nWprowadz dane: ";
		cin >> p1 >> p2  >> p3;

		cout << Funct(p1, p2, p3, w1, w2, w3);

	}

	// Z NAUCZYCIELEM

	/*cout << "Z NAUCZYCIELEM\n\n";
	cout << "START\nw1=" << w1 << "\nw2=" << w2 << "\nw3=" << w3 << endl;

	for (int i = 0; i < l_inter; i++) {

		for (int j = 0; j < 8; j++) {

			double y = Funct(Stru[j].x1, Stru[j].x2, Stru[j].x3, w1, w2, w3);

			w1 += n* Stru[j].d*Stru[j].x1;
			w2 += n *Stru[j].d*Stru[j].x2;
			w3 += n*Stru[j].d*Stru[j].x3;
		}

	}

	cout << "END\nw1=" << w1 << "\nw2=" << w2 << "\nw3=" << w3 << endl;

	while (true) {

		cout << "\nWprowadz dane: ";
		cin >> p1 >> p2 >> p3;

		cout << Funct(p1, p2, p3, w1, w2, w3);
		}
*/
	


	system("pause");
}

int Funct(double x, double  y, double z, double  w1, double  w2, double w3) {// funkcja progowa unipolarna

	double res = x*w1 + y*w2  + z*w3;

	if (res >= 0)
		return 1;

	return -1;
}

bool RedOrBlue(double x, double  y, double  w1, double  w2) {// funkcja progowa unipolarna

	double res = x*w1 + y*w2;

	if (res >= 0)
		return true;

	return false;
}