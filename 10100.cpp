#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int c = 1, m[501][501];
string s1, s2;
vector<string> v1, v2;
vector<string> toVector(string s);

int main() {
	while (getline(cin, s1)) {
		getline(cin, s2);
		if (s1.length() == 0 || s2.length() == 0)
			printf("%2d. Blank!\n", c++);
		else {
			v1 = toVector(s1);
			v2 = toVector(s2);

			memset(m, 0, m[0][0] * (v1.size() + 1) * (v2.size() + 1));

			for (int i = 1; i < v1.size(); i++) {
				for (int j = 1; j < v2.size(); j++) {
					m[i][j] = max(m[i - 1][j], m[i][j - 1]);
					if (v1[i].compare(v2[j]) == 0) {
						m[i][j] = m[i - 1][j - 1] + 1;
					}
				}
			}
			printf("%2d. Length of longest match: %d\n", c++, m[v1.size() - 1][v2.size() - 1]);
		}
	}
	return 0;
}

vector<string> toVector(string s) {
	vector<string> v;
	v.push_back(" ");
	bool isWord = false;
	string word = "";
	for (int i = 0; i <= s.length(); i++) {
		char c = s[i];
		if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9') {
			if (isWord) {
				word += c;
			}
			else {
				word = c;
				isWord = true;
			}
		}
		else {
			if (isWord) {
				v.push_back(word);
				isWord = false;
			}
		}
	}

	return v;
}