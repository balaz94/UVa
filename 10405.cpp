#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int i, j, dp[1001][1001];
string s1, s2;

int main() {
	while (getline(cin, s1)) {
		getline(cin, s2);
		memset(dp, 0, sizeof(dp));

		for (i = 0; i < s1.size(); i++) {
			for (j = 0; j < s2.size(); j++) {
				dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
				if (s1.at(i) == s2.at(j))
					dp[i + 1][j + 1] = dp[i][j] + 1;
			}
		}

		cout << dp[s1.size()][s2.size()] << endl;
	}
	return 0;
}