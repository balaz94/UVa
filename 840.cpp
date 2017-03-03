#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <set>

using namespace std;

int n, N, M, E, last[52];
bool matrix[52][52], used[52], yes;
string chars[52];

void getSequence(int i);
set<set<int>> setUsedPath;

int main() {
	for (int i = 0; i < 52; i++) {
		if (i < 26) {
			chars[i] = (char)('A' + i);
		}
		else {
			chars[i] = (char)('a' + i - 26);
		}
	}
	cin >> n;
	while (n--) {
		setUsedPath.clear();
		memset(matrix, false, sizeof(matrix[0][0]) * 52 * 52);
		memset(used, false, sizeof(used[0]) * 52);
		yes = false;
		cin >> N;
		cin >> M;
		cin >> E;
		while (E--) {
			string s;
			cin >> s;
			if (s.at(0) < 'a') {
				matrix[s.at(0) - 'A'][s.at(2) - 'a' + 26] = true;
				used[s.at(0) - 'A'] = true;
				used[s.at(2) - 'a' + 26] = true;
			}
			else {
				matrix[s.at(0) - 'a' + 26][s.at(2) - 'A'] = true;
				used[s.at(2) - 'A'] = true;
				used[s.at(0) - 'a' + 26] = true;
			}
		}

		for (int i = 0; i < 52; i++) {
			if (used[i]) {
				getSequence(i);
			}
		}

		if (!yes)
			cout << "NO" << endl;

		if (n)
		cout << endl;
	}
	return 0;
}

void getSequence(int i) {
	int start = i;
	memset(last, -1, sizeof(last));
	last[start] = start;
	queue<int> q;
	for (int j = 0; j < 52; j++) {
		if (matrix[start][j]) {
			last[j] = start;
			q.push(j);
		}
	}
	
	while (!q.empty()) {
		int p = q.front();
		q.pop();

		for (int j = 0; j < 52; j++) {
			if (matrix[p][j]) {
				if (j == start) {
					set<int> mySet;
					mySet.insert(start);
					string s = "" + chars[start];
					while (p != start) {
						s = chars[p] + "-" + s;
						mySet.insert(p);
						p = last[p];
					}
					if (setUsedPath.find(mySet) == setUsedPath.end()) {
						if (!yes) {
							cout << "YES" << endl;
							yes = true;
						}
						setUsedPath.insert(mySet);
						cout << chars[start] <<  '-' << s << endl;
					}
				}

					if (last[j] == -1) {
					last[j] = p;
					q.push(j);
				}
			}
		}
	}
}