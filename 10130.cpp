#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int T, N, G, i, j, dp[1001][31], prices[1001], weight[1001], g, sum;

int main() {
	cin >> T;
	while (T--) {
		cin >> N;
		memset(dp, 0, sizeof(dp));

		for (i = 1; i <= N; i++) {
			cin >> prices[i];
			cin >> weight[i];
		}

		for (i = 1; i <= N; i++) {
			for (j = 0; j < 31; j++) {
				if (weight[i] > j) {
					dp[i][j] = dp[i - 1][j];
				}
				else {
					dp[i][j] = max(dp[i - 1][j], dp[i-1][j - weight[i]] + prices[i]);
				}
			}
		}

		sum = 0;
		cin >> G;
		for (i = 0; i < G; i++) {
			cin >> g;
			sum += dp[N][g];
		}

		cout << sum << endl;
	}
	return 0;
}