#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int i, j, k, dp[101][101];
string s1, s2;

int main() {
	for (k = 1; ; k++) {
		getline(cin, s1);
		if (!s1.compare("#")) {
			return 0;
		}
		getline(cin, s2);

		memset(dp, 0, sizeof(dp));

		for (i = 0; i < s1.size(); i++) {
			for (j = 0; j < s2.size(); j++) {
				dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
				if (s1.at(i) == s2.at(j)) {
					dp[i + 1][j + 1] = dp[i][j] + 1;
				}
			}
		}

		cout << "Case #" << k << ": you can visit at most " << dp[s1.size()][s2.size()] << " cities." << endl;
	}
}