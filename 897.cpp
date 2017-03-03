#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;

int a[1000];
bool isPrime(int n);
bool isAnagramatic(int n);

int main() {
	int z = 0;
	for (int i = 999; i > 0; i--) {
		a[i] = z;
		if (isPrime(i) && isAnagramatic(i)) {
			z = i;
		}
		if (i == 100 || i == 10) z = 0;
	}
	int n;
	while (cin >> n) {
		if (n == 0) {
			return 0;
		}
		if (n > 999) cout << "0" << endl;
		else {
			cout << a[n] << endl;
			
		}
	}
	return 0;
}

bool isPrime(int n) {
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	int max = sqrt(n) + 1;
	for (int i = 3; i < max; i += 2) {
		if (n % i == 0) return false;
	}
	return true;
}

bool isAnagramatic(int n) {
	if (n < 10) return true;
	if (n < 100) {
		int a = n % 10;
		int b = n / 10;
		if (isPrime(a * 10 + b)) return true;
	}
	else {
		int a = n % 10;
		n /= 10;
		int b = n % 10;
		int c = n / 10;
		return isPrime(a * 100 + c * 10 + b) && isPrime(b * 100 + a * 10 + c) && isPrime(b * 100 + c * 10 + a)
			&& isPrime(c * 100 + a * 10 + b) && isPrime(c * 100 + b * 10 + a);
	}
	return false;
}