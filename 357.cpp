#include <iostream>

using namespace std;

long long dp[30051];
int i, j, n, p[5] = { 1, 5, 10, 25, 50 };

int main() {
	dp[0] = 1;
	
	for (j = 0; j < 5; j++) {
		for (i = 0; i < 30000; i++)
			dp[i + p[j]] += dp[i];
	}

	while (cin >> n) {
		if (n < 5) {
			cout << "There is only 1 way to produce " << n << " cents change." << endl;
		}
		else {
			cout << "There are " << dp[n] << " ways to produce " << n << " cents change." << endl;
		}
	}
	return 0;
}
