#include <iostream>
#include <string>
#include <cstring>

using namespace std;
int n, m, i, j, k;
bool matrix[101][101];

int main() {
	while (cin >> n) {
		memset(matrix, false, sizeof(matrix[0][0]) * 101 * 101);
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				cin >> k;
				matrix[i][j] = k == 1;
			}
		}
		m = 0;
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (matrix[i][j]) {
					for (k = 0; k < n; k++) {
						if (((i < j && j < k) || (i > j && j > k)) && matrix[j][k] && matrix[k][i]) {
							cout << to_string(i + 1) << " " << to_string(j + 1) << " " << to_string(k + 1) << endl;
							m++;
						}
					}
				}
			}
		}
		cout << "total:" << to_string(m) << endl << endl;
	}
	return 0;
}