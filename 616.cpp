#include <iostream>
#include <math.h>
#include <string>
using namespace std;
int n, m;
bool b;

bool search(int i, int c);

int main() {
	while (true) {
		cin >> n;
		if (n < 0)
			return 0;
		b = false;
		m = sqrt((double)n) + 1;
		for (int i = m; i > 1; i--) {
			if (search(i, n)) {
				cout << to_string(n) << " coconuts, " << to_string(i) << " people and 1 monkey" << endl;
				b = true;
				break;
			}
		}
		if (!b)
			cout << to_string(n) << " coconuts, no solution" << endl;
	}
}

bool search(int i, int c) {
	for (int j = 0; j < i; j++) {
		c--;
		if (c % i == 0) {
			int a = c / i;
			c = a * (i - 1);
		}
		else
			return false;
	}
	return c % i == 0;
}