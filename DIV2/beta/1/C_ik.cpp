//ik_e verion
//geometry - circle and triangle
//formula: R = abc/4S; n = pi/gcd(A,B,C)
#include<bits/stdc++.h>
using namespace std;
#define eps 1e-4

double gcd(double x, double y){
	while (fabs(x) > eps && fabs(y) > eps){
		if (x > y)	x -= floor(x / y) * y;
		else		y -= floor(y / x) * x;
	}
	return x + y;
}

int main(){

	double x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	double a, b, c;

	a = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
	b = sqrt((x1 - x3)*(x1 - x3) + (y1 - y3)*(y1 - y3));
	c = sqrt((x2 - x3)*(x2 - x3) + (y2 - y3)*(y2 - y3));

	double A, B, C;

	A = acos((b*b + c*c - a*a) / (2 * b*c));
	B = acos((a*a + c*c - b*b) / (2 * a*c));
	C = acos((a*a + b*b - c*c) / (2 * a*b));

	double S = (a + b + c) / 2.0;

	S = sqrt(S*(S - a)*(S - b)*(S - c));

	double R = a*b*c / (4 * S);
	double n = (2 * acos(0)) / (gcd(gcd(A, B), C));
	double Area = n / 2.0*R*R*sin(2 * 2 * acos(0) / n);

	printf("%.4lf", Area);
	return 0;
}
