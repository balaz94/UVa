#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int t, i, j;
long long tmp, limit, memo[201];
string s;

int main() {
	cin >> t;
	limit = INT32_MAX;
	while (t--) {
		cin >> s;
		memset(memo, 0, sizeof(memo));
		for (i = 0; i < s.size(); i++) {
			tmp = 0;
			for (j = i; j < s.size(); j++) {
				tmp = (tmp * 10) + (s[j] - '0');
				if (tmp < limit) {
					memo[j + 1] = max(memo[j + 1], memo[i] + tmp);
				}
				else {
					break;
				}
			}
		}
		cout << memo[s.size()] << endl;
	}
}