#include<stdio.h>
#include<cmath>
#define ll long long
using namespace std;

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		ll a, b, mul;
		scanf("%lld %lld", &a, &b);
		mul = a * b;

		ll k = round(cbrt(mul));

		if (k * k * k == mul) {
			if ((a % k) == 0 && (b % k) == 0) {
				puts("Yes");
			}
			else {
				puts("No");
			}
		}
		else {
			puts("No");
		}
	}
}
