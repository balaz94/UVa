#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int T, dp[1001][1001];
string s;

int search(int i, int j);

int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> s;
		memset(dp, -1, sizeof(dp));
		cout << "Case " << t << ": " << search(0, s.size() - 1) << endl;
	}
	return 0;
}

int search(int i, int j) {
	if (i > j)
		return 0;

	if (dp[i][j] != -1)
		return dp[i][j];

	int pom;

	if (s.at(i) == s.at(j))
		pom = search(i + 1, j - 1);
	else {
		pom = min(search(i, j - 1), search(i + 1, j));
		pom = min(pom, search(i + 1, j - 1));
		pom++;
	}

	dp[i][j] = pom;
	return pom;
}