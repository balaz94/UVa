#include <iostream>
#include <string>
#include <map>
using namespace std;

int c[200001], id[200001], n, l, z, a, b, p1, p2, use;
map<string, int> names;

int find(int p);
void join(int p, int q);

int main() 
{
	cin >> z;
	while (z--) {
		cin >> n;
		l = n * 2 + 1;
		names.clear();
		for (int i = 1; i < l; i++) {
			id[i] = i;
			c[i] = 1;
		}
		use = 1;

		for (int i = 0; i < n; i++) {
			string s1, s2;
			cin >> s1;
			cin >> s2;
			a = names[s1];
			if (a == 0) {
				a = use;
				names[s1] = use++;
			}
			b = names[s2];
			if (b == 0) {
				b = use;
				names[s2] = use++;
			}
			
			p1 = find(a);
			p2 = find(b);

			if (p1 == p2)
				cout << c[p1] << endl;
			else {
				if (c[p1] > c[p2]) {
					join(p2, p1);
					cout << c[p1] << endl;
				}
				else {
					join(p1, p2);
					cout << c[p2] << endl;
				}
			}
		}
	}
	return 0;
}

int find(int p) {
	while (p != id[p]) {
		p = id[p];
	}
	return p;
}

void join(int p, int q) {
	c[q] += c[p];
	id[p] = id[q];
}