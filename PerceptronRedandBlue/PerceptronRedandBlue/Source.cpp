#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Point {

	double	x,
		y;

	int color; // 1 = red, 0 = blue
};

bool RedOrBlue(double x, double  y, double  w1, double  w2);

int main() {

	srand(time(NULL));

	Point Ptable[10] = {
		(1.0,1.5,1), // RED
		(1.2,2.3,1),
		(1.8,2.5,1),
		(1.4,2.3,1),
		(1.3,2.4,1),

		(3.0,1.5,0), // BLUE
		(3.3,2.7,0),
		(3.1,2.9,0),
		(3.8,3.2,0),
		(3.6,3,0)
	};

	double	w1 = ((rand() % 10) - 5) / 10.,
		w2 = ((rand() % 10) - 5) / 10.,
		res = 0,
		n = 0.01, // niewielki współczynnik uczenia
		b = 0, // ?
		p1 = 0,
		p2 = 0;

	int Pcolor = 0;


	cout << "START\nw1=" << w1 << "\nw2=" << w2 << endl;


	while (true) {

		double	w1b = w1,
			w2b = w2;

		for (int i = 0; i < 10; i++) {

			if (RedOrBlue(Ptable[i].x, Ptable[i].y, w1, w2))
				Pcolor = 1;
			else
				Pcolor = 0;

			if (Pcolor != Ptable[i].color) {

				w1 += n * (Ptable[i].color - Pcolor) * Ptable[i].x;
				w2 += n * (Ptable[i].color - Pcolor) * Ptable[i].y;
				b += n * (Ptable[i].color - Pcolor);
			}
		}

		if (w1b == w1 && w2b == w2)
			break;
	}

	cout << "END\nw1=" << w1 << "\nw2=" << w2 << endl;

	while (true) {

		cout << "\nWprowadz punkt: ";
		cin >> p1 >> p2;

		cout << (RedOrBlue(p1, p2, w1, w2) ? "RED" : "BLUE");

	}

	system("pause");

}

bool RedOrBlue(double x, double  y, double  w1, double  w2) {// funkcja progowa unipolarna

	double res = x*w1 + y*w2;

	if (res >= 0)
		return true;

	return false;
}