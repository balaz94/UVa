#include <iostream>
#include <cstring>

using namespace std;

int n, m, t, beer[10001], burger[10001];

int main() {
	while (cin >> m) {
		cin >> n;
		cin >> t;

		memset(beer, 0, sizeof(beer));
		memset(burger, -1, sizeof(burger));

		burger[0] = 0;

		for (int i = 0; i <= t; i++) {

			if (i > 0) {
				if (burger[i] == -1) {
					burger[i] = burger[i - 1];
					beer[i] = beer[i - 1] + 1;
				}
			}

			if (i + m <= t) {
				if (burger[i + m] == -1) {
					burger[i + m] = burger[i] + 1;
					beer[i + m] = beer[i];
				}
				else {
					if (beer[i] < beer[i + m]) {
						burger[i + m] = burger[i] + 1;
						beer[i + m] = beer[i];
					}
					else if (beer[i] == beer[i + m] && burger[i + m] < burger[i] + 1) {
						burger[i + m] = burger[i] + 1;
					}
				}
			}
			if (i + n <= t) {
				if (burger[i + n] == -1) {
					burger[i + n] = burger[i] + 1;
					beer[i + n] = beer[i];
				}
				else {
					if (beer[i] < beer[i + n]) {
						burger[i + n] = burger[i] + 1;
						beer[i + n] = beer[i];
					}
					else if (beer[i] == beer[i + n] && burger[i + n] < burger[i] + 1) {
						burger[i + n] = burger[i] + 1;
					}
				}
			}
		}

		if (beer[t] == 0)
			cout << burger[t] << endl;
		else
			cout << burger[t] << " " << beer[t] << endl;

	}
	return 0;
}