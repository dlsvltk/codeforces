#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

long long int gcd(long long int a, long long int b) { return b ? gcd(b, a%b) : a; }

int main() {
	long long int m, b;
	cin >> m >> b;
	
	pair<long long int, long long int> from, to;
	from = { 0, b };
	to = { m*b, 0 };

	pair<long long int, long long int> unit = { (to.first - from.first) / gcd(abs(to.first - from.first), abs(to.second - from.second)), (to.second - from.second) / gcd(abs(to.first - from.first), abs(to.second - from.second)) };
	pair<long long int, long long int> start = from;
	
	long long int result = 0;


	while (start != to) {
		long long int tmp = 0;
		tmp = (start.first + 1) * (start.second + 1) * (start.first + start.second) / 2;
		result = max(result, tmp);
		start = { start.first + unit.first, start.second + unit.second };
	}
	long long int tmp = 0;
	tmp = (start.first + 1) * (start.second + 1) * (start.first + start.second) / 2;
	result = max(result, tmp); 
	cout << result << endl;
}
