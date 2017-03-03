#include <iostream>

using namespace std;

int T, a, b;
int main() {
	cin >> T;
	while (T--) {
		bool right = true;
		cin >> a;
		for (int i = 0; i < 4; i++) {
			cin >> b;
			if (b - 1 != a)
				right = false;
			a = b;
		}
		if (right)
			cout << "Y" << endl;
		else
			cout << "N" << endl;
	}
	return 0;
}