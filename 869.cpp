#include <iostream>
#include <queue>
#include <set>
#include <cstring>

using namespace std;
int n1, n2, c;
bool yes, a1[26][26], a2[26][26];

bool isEquivalent(int start, set<int> mySet, bool matrix[26][26]);

int main() {
	cin >> c;
	while (c--) {
		cin >> n1;
		memset(a1, false, sizeof(a1[0][0]) * 26 * 26);
		memset(a2, false, sizeof(a2[0][0]) * 26 * 26);

		yes = true;

		for (int i = 0; i < n1; i++) {
			char ch1, ch2;
			cin >> ch1;
			cin >> ch2;
			a1[ch1 - 'A'][ch2 - 'A'] = true;
			a1[ch2 - 'A'][ch1 - 'A'] = true;
		}

		cin >> n2;
		for (int i = 0; i < n2; i++) {
			char ch1, ch2;
			cin >> ch1;
			cin >> ch2;
			a2[ch1 - 'A'][ch2 - 'A'] = true;
			a2[ch2 - 'A'][ch1 - 'A'] = true;
		}

		for (int i = 0; i < 26; i++) {
			set<int> mySet;
			for (int j = 0; j < 26; j++) {
				if (a1[i][j]) {
					mySet.insert(j);
				}
			}
			if (!isEquivalent(i, mySet, a2)) {
				yes = false;
				break;
			}
		}

		if (yes) {
			for (int i = 0; i < 26; i++) {
				set<int> mySet;
				for (int j = 0; j < 26; j++) {
					if (a2[i][j]) {
						mySet.insert(j);
					}
				}
				if (!isEquivalent(i, mySet, a1)) {
					yes = false;
					break;
				}
			}
		}

		if (yes)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		if (c)
			cout << endl;
	}
	return 0;
}

bool isEquivalent(int start, set<int> mySet, bool matrix[26][26]) {
	queue<int> q;
	bool used[26];
	for (int i = 0; i < 26; i++) {
		used[i] = false;
		if (matrix[start][i]) {
			used[i] = true;
			q.push(i);
		}
	}

	while (!q.empty()) {
		int p = q.front();
		q.pop();

		mySet.erase(p);

		for (int i = 0; i < 26; i++) {
			if (!used[i] && matrix[p][i]) {
				used[i] = true;
				q.push(i);
			}
		}
	}

	return mySet.empty();
}