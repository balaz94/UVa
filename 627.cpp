#include <iostream>
#include <string>
#include <cstring>
#include <queue>

using namespace std;
int n, m, use[301];
bool matrix[301][301];
string line, num, path, s;

string getPath(int a, int b);

int main() {
	while (cin >> n) {
		memset(matrix, false, sizeof(matrix[0][0]) * 301 * 301);
		for (int i = 1; i <= n; i++) {
			cin >> line;
			int j = 0;
			while (line.at(j) != '-') {
				j++;
			}
			num = "";
			for (++j; j < line.length(); j++) {
				if (line.at(j) == ',') {
					matrix[i][atoi(num.c_str())] = true;
					num = "";
				}
				else {
					num += line.at(j);
				}
			}
			if (num.length() > 0) {
				matrix[i][atoi(num.c_str())] = true;
			}
		}
		cin >> m;
		cout << "-----" << endl;
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a;
			cin >> b;
			path = getPath(a, b);
			if (path.length() < 2) {
				cout << "connection impossible" << endl;
			}
			else {
				cout << path << endl;
			}
		}
	}
	return 0;
}

string getPath(int a, int b) {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		use[i] = 0;
		if (matrix[a][i]) {
			if (b == i) {
				return to_string(a) + " " + to_string(b);
			}
			q.push(i);
			use[i] = a;
		}
	}

	while (!q.empty()) {
		int p = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (matrix[p][i] && !use[i]) {
				if (i == b) {
					s = to_string(p) + " " + to_string(b);
					while (p != a) {
						p = use[p];
						s = to_string(p) + " " + s;
					}
					return s;
				}
				use[i] = p;
				q.push(i);
			}
		}
	}
	return "";
}