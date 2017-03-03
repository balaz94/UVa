#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int i, j, t, dp[1005][1005];
string s;

int main() {
	getline(cin, s);
	t = atoi(s.c_str());
	while (t--) {
		getline(cin, s);
		memset(dp, 0, sizeof(dp));
		for (i = 0; i < s.size(); i++) {
			for (j = 0; j < s.size(); j++) {
				dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
				if (s.at(i) == s.at(s.size() - 1 - j)) {
					dp[i + 1][j + 1] = dp[i][j] + 1;
				}
			}
		}

		cout << dp[s.size()][s.size()] << endl;
	}
	return 0;
}